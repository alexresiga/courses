from domain.Player import Player
from repository.Repository import Repository

repo = Repository('player.txt', Player.read_line, Player.write_line)
jucator = Player(12, 'alex')
try:
    repo.store_item(jucator)

except Exception as exc:
    print(str(exc))