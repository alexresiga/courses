class WeaponValidator:
    def __int__(self):
        pass

    @staticmethod
    def validateQty(qty):
        if int(qty) < 5000:
            raise ValueError("Insufficient quantity")
        return True
