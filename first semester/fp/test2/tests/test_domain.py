import unittest
from domain.Weapon import Weapon


class TestDomain(unittest.TestCase):
    def setUp(self):
        self.ident = 1
        self.weapon_type = 'shield'
        self.material = 'gold'
        self.value = 5000
        self.weapon = Weapon(self.ident, self.weapon_type, self.material, self.value)
        self.weapon2 = Weapon(2, 'shield', 'gold', 6000)
        self.weapon3 = Weapon(3, 'sword', 'gold', 5000)

    def testdomain(self):
        self.assertEqual(self.weapon.get_material(), 'gold')

if __name__ == '__main__':
    unittest.main()
