class PriorityQueue:
    def __init__(self):
        self.size = 0
        self.queue = []

    def repair_heap(self, index):
        while index != 0 and self.queue[int((index - 1) / 2)][0] > self.queue[index][0]:
            self.queue[index], self.queue[int((index - 1) / 2)] = self.queue[int((index - 1) / 2)], self.queue[index]
            index = int((index - 1) / 2)

    def insert(self, key):
        self.size += 1
        self.queue.append(key)
        index = self.size - 1
        self.repair_heap(index)

    def decrease_key(self, index, newValue):
        if index < self.size:
            if self.queue[index][0] > newValue:
                self.queue[index][0] = newValue
                self.repair_heap(index)

    def __str__(self):
        return f'{self.queue}'

    __repr__ = __str__

    def find_min(self):
        if self.size > 0:
            print(self.queue[0][0])

    def heapify(self, i):
        left_child = (2 * i) + 1
        right_child = (2 * i) + 2
        smallest = i
        if left_child < self.size and self.queue[left_child][0] < self.queue[i][0]:
            smallest = left_child
        if right_child < self.size and self.queue[right_child][0] < self.queue[smallest][0]:
            smallest = right_child
        if smallest != i:
            self.queue[i], self.queue[smallest] = self.queue[smallest], self.queue[i]
            self.heapify(smallest)

    def extract_min(self):
        if self.size > 0:
            mini = self.queue[0]
            self.queue[0], self.queue[self.size - 1] = self.queue[self.size - 1], self.queue[0]
            self.size -= 1
            self.queue.pop()
            self.heapify(0)
            return mini
