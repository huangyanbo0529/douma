
class DynamicArrayStack:

    def __init__(self):
        self.data = []

    def getSize(self):
        return len(self.data)

    def isEmpty(self):
        return len(self.data) == 0

    def push(self, e):
        self.data.append(e)

    def pop(self):
        return self.data.pop()

    def peek(self):
        return self.data[self.getSize() - 1]