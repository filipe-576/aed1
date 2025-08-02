class MedianFinder:

    def __init__(self):
        self.array = SortedList()

    def addNum(self, num: int) -> None:
        self.array.add(num)


    def findMedian(self) -> float:
        size: int = len(self.array)
        half: int = int(size / 2)
        return self.array[half] if size % 2 != 0 else (self.array[half - 1] + self.array[half]) / 2



# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()