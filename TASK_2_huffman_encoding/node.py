class Node:
    def __init__(self, symbol: str, frequency=1, left_child=None, right_child=None):
        self.symbol = symbol
        self.freq = frequency
        self.left_child = left_child
        self.right_child = right_child
        self.bit = ""
        self.code = ""

    def inc(self):
        self.freq += 1

    def __str__(self):
        return f"[{self.freq}] '{self.symbol}' -> {self.code}"

    def __repr__(self):
        return self.__str__()

    def __eq__(self, other):
        if isinstance(other, Node):
            return self.symbol == other.symbol
        else:
            return False
