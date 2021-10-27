#!/bin/env ruby

SOC_NAME="CH57x"

puts "Input Peripheal name:"
periph_name = gets
periph_name.gsub!("\n", '')

puts "Input reg name:"
periph_reg = gets
periph_reg.gsub!("\n", '')

puts "Input reg bits:"
periph_reg_bits_string = gets
periph_reg_bits = periph_reg_bits_string.to_i

puts "This register has #{periph_reg_bits}bits."

current_bit = 0
periph_reg_fields = []

until current_bit == periph_reg_bits do
  puts "Input field length at bit #{current_bit}"
  current_field_len_string = gets
  current_field_len = current_field_len_string.to_i

  puts "Input field name:"
  current_field_name = gets
  current_field_name.gsub!("\n", '')

  periph_reg_fields.push({:name => current_field_name, :start => current_bit, :length => current_field_len})

  current_bit += current_field_len
end

puts "/* #{SOC_NAME}_#{periph_name} #{periph_reg } Register Definition */"

periph_reg_fields.each do |f|
  pos_string = "#{SOC_NAME}_#{periph_name}_#{periph_reg}_#{f[:name]}_Pos"
  msk_string = "#{SOC_NAME}_#{periph_name}_#{periph_reg}_#{f[:name]}_Msk"

  bitmask_string = ""
  if(f[:length] == 1) then
    bitmask_string = "1UL"
  else
    bitmask_string = "0x#{(2.pow(f[:length]) - 1).to_s(16).upcase}UL"
  end

  puts "#define #{pos_string} #{f[:start]}"
  if f[:start] == 0 then
    puts "#define #{msk_string} (#{bitmask_string}) /* << #{pos_string} */"
  else
    puts "#define #{msk_string} (#{bitmask_string} << #{pos_string})"
  end

  puts ""
end