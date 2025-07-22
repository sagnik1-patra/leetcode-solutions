class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        # Edge case: overflow
        if dividend == INT_MIN and divisor == -1:
            return INT_MAX
        if dividend == INT_MIN and divisor == 1:
            return INT_MIN

        # Determine sign of result
        negative = (dividend < 0) != (divisor < 0)

        # Work with positive numbers
        dividend, divisor = abs(dividend), abs(divisor)
        quotient = 0

        # Subtract multiples of divisor
        while dividend >= divisor:
            temp, multiple = divisor, 1
            while dividend >= (temp << 1):
                temp <<= 1
                multiple <<= 1
            dividend -= temp
            quotient += multiple

        # Apply sign
        if negative:
            quotient = -quotient

        # Clamp result to 32-bit signed integer range
        return max(INT_MIN, min(INT_MAX, quotient))
