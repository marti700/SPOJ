=begin
 the solution to this problem is very easy (desappointingly easy)
 after a bit of thinkig i realize that all the numbers which cube ends in 888
 increase from 250 to 250 (exepting the first one with is 192)
 for example 192 + 250 = 442 which is the second number which cube ends in 888
 and 442 + 250 = 692 which is the third number which cube ends in 888

 once you know that is easy to figure out that (N x 250) - 58 will give you the Nth number
 which its cube ends en 888.
=end


test_case = gets.chomp

test_case.to_i.times do
  input = gets.chomp
  
  puts (input.to_i * 250) - 58
end
