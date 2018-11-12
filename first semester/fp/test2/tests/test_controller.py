import unittest
from tests.test_repo import TestRepo
from service.WeaponController import WeaponController


class TestController(TestRepo):
    def setUp(self):
        TestRepo.setUp(self)
        self.controller = WeaponController(self.repo)

    def testcontroller(self):
        TestRepo.testrepo(self)
        self.controller.forge(self.ident, self.weapon_type, self.material, self.value)
        self.assertEqual(self.repo.size(), 1)
        self.repo.add(self.weapon2)
        self.repo.add(self.weapon3)
        self.controller.melt(2, 3, 'sword')
        self.assertEqual(self.repo.size(), 2)


if __name__ == '__main__':
    unittest.main()
