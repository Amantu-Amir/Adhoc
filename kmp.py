def kmp(pat, text):
	pl = len(pat)
	tl = len(text)
	lps = [0]*pl
	j = 0
	build(pat, pl, lps)
	i = 0
	while i < tl:
		if pat[j] == text[i]:
			i += 1
			j += 1
		if j == pl:
			print("Found")
			return
		elif i < tl and pat[j] != text[i]:
			if j != 0: 
				j = lps[j-1] 
			else: 
				i += 1



def build(pat, pl, lps):
	len = 0
	lps[0]
	i = 1
	while i < pl:
		if pat[i]== pat[len]: 
			len += 1
			lps[i] = len
			i += 1
		else:
			if len != 0: 
				len = lps[len-1]
			else: 
				lps[i] = 0
				i += 1


text = input()
pat = input()
kmp(pat, text)

