b = 32
v = Array.new(b, 0)

stringa = gets.to_s

unless stringa.size > b then
  valVuoto = stringa.size
end

i = b - valVuoto
j = 0

loop do
  v[i] = stringa[j].to_i

  i += 1
  j += 1

  break unless i < b
end

i = b - 1
j = 0
num = 0

while i > -1 do
  num += v[i] * (2 ** j)
  i -= 1
  j += 1
end

puts num/2
