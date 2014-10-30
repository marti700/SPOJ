test_cases = gets.chomp

test_cases.to_i.times do
  input = gets.chomp.split
  base = input[0].to_i
  index = input[1].to_i
  
  puts (base**index) % 10
end

