test_case = gets.chomp

sum = 0;

el_gancho = gets #this expression is used to read a blank line its like a tramp 

test_case.to_i.times do 
  input = gets.chomp
  
   input.to_i.times do 
    sum += gets.chomp.to_i
  end
  
  sum % input.to_i == 0 ? puts("YES") : puts("NO")   #if the sum mod the number of candy is not 0 then is not posible to put the same number of candies in n heaps
  sum = 0
  
  el_gancho = gets # this is the other obligatory place to read a blank line because each test case is separated by a blank line

end
