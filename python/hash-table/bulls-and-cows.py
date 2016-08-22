class Solution(object):
    def getHint(self, secret, guess):
        d = {}
        bulls, cows = 0, 0
        for i in xrange(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                if d.get(secret[i]):
                    d[secret[i]] += 1
                else:
                    d[secret[i]] = 1

        for i in xrange(len(secret)):
            if secret[i] != guess[i] and \
                d.get(guess[i]) > 0:
                    cows += 1
                    d[guess[i]] -= 1

        return str(bulls) + 'A' + str(cows) + 'B'
