from domain.Weapon import Weapon
from Validator.WeaponValidator import WeaponValidator


class ControllerException(Exception):
    pass


class WeaponController:
    def __init__(self, repo):
        self.__repo = repo
        self.validator = WeaponValidator()

    def forge(self, ident, weapon_type, material, quantity):
        self.validator.validateQty(quantity)
        values = {'gold': 100, 'silver': 70, 'bronze': 30}
        types = {'shield': 500, 'sword': 750}
        value = types[weapon_type]*values[material]*int(quantity)
        self.__repo.add(Weapon(ident, weapon_type, material, value))

    def melt(self, ident1, ident2, weapon_type):
        weapon1 = self.__repo.find(Weapon(ident1, '', 'gold', ''))
        weapon2 = self.__repo.find(Weapon(ident2, '', 'gold', ''))
        material = 'alloy'

        values = {'gold': 100, 'silver': 70, 'bronze': 30}
        types = {'shield': 500, 'sword': 750}
        avg = (values[weapon1.get_material()] * weapon1.get_quantity() + values[weapon2.get_material()] *
               weapon2.get_quantity()) // (weapon1.get_quantity() + weapon2.get_quantity())
        value = types[weapon_type]*avg
        self.__repo.remove(Weapon(ident1, '', 'gold', ''))
        self.__repo.remove(Weapon(ident2, '', 'gold', ''))
        self.__repo.add(Weapon(ident1, weapon_type, material, value))

    def defeatingWeapons(self, ident):
        w = Weapon(ident, '', 'gold', '')
        myweapon = self.__repo.find(w)
        result = [x for x in self.__repo.getAll() if x.get_quantity() > myweapon.get_quantity() and
                  x.get_weapon_type() != myweapon.get_weapon_type()]
        result.sort(key=lambda x: x.get_rank(), reverse=True)
        return result

