from flask import Flask, jsonify, request
from bs4 import BeautifulSoup
import requests
import lxml
app = Flask(__name__)

@app.route('/', methods = ['GET'])
def hello_world():
    try:
        name = request.args.get("name")
        return "Glen Robinson III is the " + name + " player in the NBA!"
    except Exception:
        return "glennrobinsoniiiisthebestplayerinthenba"

