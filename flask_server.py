from flask import Flask, jsonify, request
from bs4 import BeautifulSoup
import requests
import lxml
app = Flask(__name__)

@app.route('/', methods = ['GET'])
def hello_world():
    try:
        word = request.args.get("word")
        return "Glen Robinson III is the " + word + " player in the NBA!"
    except Exception:
        return "glennrobinsoniiiisthebestplayerinthenba"

