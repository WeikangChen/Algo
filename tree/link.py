
import httplib2
from bs4 import BeautifulSoup, SoupStrainer


def main():

    http = httplib2.Http()
    url = 'http://www.newyorksocialdiary.com/party-pictures'
    status, response = http.request(url)

    for link in BeautifulSoup(response, parse_only=SoupStrainer('a')):
        if link.has_attr('href'):
            href = link['href'];
            if href.startswith('/party-pictures/2015/'):
                print url+link['href']

if __name__ == "__main__":
    main();
