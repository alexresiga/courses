class Player:
    def __init__(self, ident, name, height=0, position='CM'):
        self.id = ident
        self.name = name
        self.height = height
        self.position = position

    @staticmethod
    def write_line(player):
        return str(player.id) + ',' + player.name + '\n'

    @staticmethod
    def read_line(line):
        parts = line.split(',')
        return Player(int(parts[0]), parts[1])

    def __str__(self):
        return str(self.id) + " " + self.name + '\n'
