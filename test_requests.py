#%%
...

#%%
from flask import Flask, jsonify, request
from bs4 import BeautifulSoup
import requests
from lxml import etree
from lxml import objectify
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import Select
from selenium.common.exceptions import NoSuchElementException
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions
import time
import re
import os

# https://stackoverflow.com/questions/48620526/how-to-use-webdriver-as-context-manager/54149666
class ManagedWebDriver:
    def __init__(self):
        options = webdriver.firefox.options.Options()
        options.headless = True
        self.driver = webdriver.Firefox(options=options)
    def __enter__(self):
        return self.driver
    def __exit__(self, exc_type, exc_val, exc_tb):
        self.driver.quit()

def stream_for_url(url):
    with ManagedWebDriver() as mydriver:
        mydriver.get(url)
        mydriver.find_element_by_id("macDesktopDialogCornerClose").click()
        time.sleep(1)
        mydriver.find_element_by_xpath("//div[contains(@class, \"playButtonContainer\")]/a[contains(@class, \"guideItemLink\")][1]").click()
        time.sleep(5)
        link = mydriver.find_element_by_xpath("//audio").get_attribute('src')
        return link

def parse_teams():
    with open('./html.txt', 'r') as f:
        html_text = f.read()
    all_teams = {}
    misses = {}
    matches = re.findall(r'(/radio/([a-zA-Z\-]*?)-Sports-Network-c[0-9]*?/)', html_text)
    for url, team_name in matches:
        team_name = re.sub('\-', ' ', team_name)
        url = f'http://www.tunein.com{url}'
        webtext = requests.get(url).text
        match = re.search(r'/radio/[a-zA-Z\-]*?-Football-s[0-9]*?/', webtext)
        if match:
            football_url = f'http://www.tunein.com{match.group(0)}'
            all_teams[team_name] = football_url
        else:
            misses[team_name] = url
    return all_teams, misses

#%%
teams, misses = parse_teams()

#%%
with open("teams.txt", "w") as fi:
    for team in sorted(teams.keys()):
        print(team, teams[team])
        print(team, teams[team], file=fi)
print("----------------")
for miss in misses:
    print("Missed:", miss, misses[miss])
        

#%%
stream_for_url("http://www.tunein.com/radio/Oregon-Football-s206509/")

#%%
