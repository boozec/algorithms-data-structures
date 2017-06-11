fib = []
fib.push 1
fib.push 1

def fibonacci(n, fib)
  for i in 2...n do
    fib.push fib[i-1] + fib[i-2]

    break if fib[i] > n
  end

  return i
end

File.open('input.txt', 'r') do |fin|
  N = fin.gets.to_i
end

lst = fibonacci(N, fib)

fib = fib.reverse

somma = 0
seq = []

for i in 0...fib.length-1 do
  potSomma = somma + fib[i]

  if potSomma < N
    somma = potSomma
    seq << 1
  else
    seq << 0
  end
end

seq << 1
seq = seq.reverse

seq.pop if N == 1 || N > 4

File.open('output.txt', 'w') do |fout|
  seq.each {|c| fout.print c}
end
