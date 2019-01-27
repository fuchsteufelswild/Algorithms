s = input()
st = []
length = len(s)
res = 0

for i in range(length - 1, -1, -1):
    if(int(s[i]) % 2 == 0):
        res += 1
    st.append(res)

st.reverse()

for i in range(length):
    print(st[i], end = ' ')
