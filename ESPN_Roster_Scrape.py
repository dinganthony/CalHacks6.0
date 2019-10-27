from flask import Flask, jsonify, request
from bs4 import BeautifulSoup
import requests
from xmljson import badgerfish as bs

r = requests.get(f'https://www.espn.com/mens-college-basketball/teams')
soup = BeautifulSoup(r.content, 'html.parser') 
# grab HTML page
TeamName = []
TeamURL = []
for item in soup.select('h2'):
    TeamName.append(item.text)
# Scrape Team Names
for item in list(soup.select("span.TeamLinks__Link a")):
    if item.text == 'Roster':
        TeamURL.append(getattr(item,"attrs")['href'])
    else:
        continue
# Scrape the ulr that leads to team roster (since each team is assigned an id that is not consistent)

# for link in TeamURL: Do another scrape for team URLs and create a list of player names
output = [len(TeamName),len(TeamURL)]
print(output)

# <span class="TeamLinks__Link n9 nowrap"><a class="AnchorLink" href="/mens-college-basketball/team/roster/_/id/2066">Roster</a></span>