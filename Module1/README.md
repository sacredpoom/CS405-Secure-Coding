This week's assignment goals were:
- Detect when a numeric overflow or underflow is about to happen
- Write code to prevent the numeric overflow or underflow from happening
- Protect your code from underflow and overflow in any of the standard C/C++ data types

See code changes made here: [Source.cpp](NumericOverflows/NumericOverflows/Source.cpp)

Module One Process Summary with explanation and snippets included here: [Module1ProcessSummary.docx](Module1ProcessSummary.docx)


**Overflow:** Overflow is the easier of the two cases to manage so that was the first goal. Using the template provided, all that needed to be done was to verify 
whether the result would result in an overflow and inform the user. A change was implemented to the add_numbers template to return a tuple containing both the 
result, and a Boolean flag to inform of possible overflow. A simple check to see if adding the adding the increment to result would cause an overflow was added 
in an if-statement which flips the flag and breaks. This necessitated changes to the test_overflow function to handle the return of a tuple instead of just the 
result. If-statements are again used to check whether the flag indicates an overflow, and prints output to user. 

**Underflow:** Handling underflow was slightly more complicated than overflow. Again, the template was modified to return a tuple of both the result, and a Boolean 
indicator similar to the overflow changes. An if-statement is used to determine whether the decrement is greater than the result, OR the result minus the decrement 
would be less than the limit. The first part handles unsigned types as a greater decrement than result causes an underflow since it cannot go below zero. The second 
part is similar to the overflow logic, if the arithmetic occurs and it results in a value lower than the limit there is again an issue. In either of these cases the 
Boolean is flipped and the function returns. Like the overflow process, test_underflow required updating to handle the tuple return. If-else statements are used to 
check the flag, and display output. If no underflow occurs the result is displayed and if underflow would occur the user is informed. Although there should be no 
overflow or underflow on the tests stating without, handling is implemented as good practice in case something unexpected occurs. Like the overflow process, 
test_underflow required updating to handle the tuple return. If-else statements are used to check the flag, and display output. If no underflow occurs the result is 
displayed and if underflow would occur the user is informed. Although there should be no overflow or underflow on the tests stating without, handling is implemented 
as good practice in 
