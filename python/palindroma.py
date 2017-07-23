# def palindromo(parola, start, end):
#     if start >= end:
#         return True
#     elif parola[start] == parola[end]:
#         return palindromo(parola, start+1 , end-1)
#     else:
#         return False
#
#
# parola = input('Parola: ')
#
# if palindromo(parola, 0, len(parola)-1):
#     print('Palindroma')
# else:
#     print('Non palindroma')

parola = raw_input('Parola: ')

if parola == parola[::-1]:
    print('Palindroma')
else:
    print('Non palindroma')