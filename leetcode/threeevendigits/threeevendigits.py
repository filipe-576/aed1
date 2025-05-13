class Solution(object):
    def findEvenNumbers(self, digits: list[int]):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        digits.sort()
        res_digits = list()
        list_size = len(digits)

        for i in range(list_size):
            for j in range(list_size):
                for k in range(list_size):
                    if (i == j or j == k or i == k or
                       digits[k] % 2 != 0 or digits[i] == 0):
                        continue
                    num = digits[i]*100 + digits[j]*10 + digits[k]
                    if num not in res_digits:
                        res_digits.append(num)
        return res_digits


sol = Solution()
digs = sol.findEvenNumbers([2, 2, 8, 8, 2])

print(digs)
