def isPalindrome1(s):
    #Returns True if s is a palindrome and False otherwise
    print ( 'isPalindrome1 called with', s)
    if len(s) <= 1:
        print ( 'About to return True from base case')
        return True
    else:
        ans = s[0] == s[-1] and isPalindrome1(s[1:-1])
        print ( 'About to return', ans)
        return ans
isPalindrome1('sssssssssssssssss' )
