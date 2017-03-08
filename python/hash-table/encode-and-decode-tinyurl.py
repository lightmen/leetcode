class Codec:
    def __init__(self):
        self.ltos = {}
        self.stol = {}
        self.s = '0123456789qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM'

    def spliturl(self, url):
        index = url.rfind("/")
        return url[0:index + 1], url[index+1:]

    def getshort(self):
        while True:
            short = ""
            for i in range(7):
                short += random.choice(self.s)
            if short not in self.stol:
                return short

        return ''

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.

        :type longUrl: str
        :rtype: str
        """
        addr, long = self.spliturl(longUrl)
        short = self.getshort()
        self.stol[short] = long
        self.ltos[long] = short
        return addr + short

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.

        :type shortUrl: str
        :rtype: str
        """
        addr, short = self.spliturl(shortUrl)
        return addr + self.stol[short]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
