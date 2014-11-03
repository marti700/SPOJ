=begin
 well this is kind of easy if you know enough math to figure this out
 if you apply the ecuation 2x + number_of_extra_apples_klaudia_has = number_of_apples_together
 the above ecuation solved for 'x' (all other members of the ecuation are constants) will give the number of apples natalia has, 
 to obtain the apples that klaudia has just substract the ecuation result from the total of apples both girls have together. 
=end


def klaudia_and_natalia_apples total_apples, klaudia_extra_apples
  klaudia_apples = (total_apples).to_i - ((total_apples.to_i - klaudia_extra_apples.to_i)/2)
  natalia_apples = (total_apples.to_i - klaudia_extra_apples.to_i)/2

  return klaudia_apples,natalia_apples
end


10.times do
  total_of_apples = gets.chomp
  klaudia_extra_apples = gets.chomp
  puts klaudia_and_natalia_apples(total_of_apples, klaudia_extra_apples)
end
