from repository.Repository import Repository
from service.WeaponController import WeaponController
from UI.ui import UI
from domain.Weapon import Weapon
repo = Repository()
repo.add(Weapon(1, 'shield', 'bronze', 2500000))
repo.add(Weapon(2, 'sword', 'bronze', 750000000))
repo.add(Weapon(3, 'sword', 'silver', 700000000))
repo.add(Weapon(4, 'sword', 'gold', 50000000000))
repo.add(Weapon(5, 'shield', 'bronze', 6000))

controller = WeaponController(repo)
ui = UI(repo, controller)
ui.start()
