class Weapon:
    def __init__(self, ident, weapon_type, material, qty):
        self.__weapon_type = weapon_type
        self.__material = material
        self.__quantity = qty
        self.__ident = ident
        values = {'gold': 3, 'silver': 2, 'bronze': 1, 'alloy': 0}
        self.__rank = values[material]

    def get_id(self):
        return self.__ident

    def set_id(self, a):
        self.__ident = a

    def get_weapon_type(self):
        return self.__weapon_type

    def get_material(self):
        return self.__material

    def get_quantity(self):
        return self.__quantity

    def set_weapon_type(self, a):
        self.__weapon_type = a

    def set_material(self, a):
        self.__material = a

    def set_quantity(self, a):
        self.__quantity = a

    def __str__(self):
        result = ''
        result += str(self.__ident) + ". " + self.__weapon_type + ' - ' + self.__material + ' - ' + str(self.__quantity)
        return result

    def __eq__(self, other):
        return isinstance(other, self.__class__) and other.get_id() == self.__ident

    def get_rank(self):
        return int(self.__rank)
