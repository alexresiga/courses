from collections import defaultdict


class Ruler:
    def __init__(self):
        self.rules = {
            "cold": {"small": "small", "medium": "medium", "high": "high"},
            "cool": {"small": "small", "medium": "medium", "high": "high"},
            "moderate": {"small": "small", "medium": "small", "high": "small"},
            "hot": {"small": "small", "medium": "small", "high": "small"},
            "very hot": {"small": "small", "medium": "small", "high": "small"}
        }

    def evaluate(self, t, c):
        texture_fuzzy = t.fuzzy()
        capacity_fuzzy = c.fuzzy()
        power_dic = defaultdict(int)
        print(texture_fuzzy)
        print(capacity_fuzzy)
        for t_key, t_value in texture_fuzzy.items():
            for c_key, c_value in capacity_fuzzy.items():
                res = self.rules[t_key][c_key]
                val = min(t_value, c_value)
                power_dic[res] = max(power_dic[res], val)

        return power_dic
