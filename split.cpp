/**
 * Algorithm: Splits up a given string at given deliminator(s) and stores the split contents in a given array.
 * 1. Accept string input_string, char separator, string arr[], and int arr_size as parameters.
 * 2. Declare variables string split = "", int count = 0, and int index_array = 0.
 * 3. Check if the given string is empty, if so stop and return 0.
 * 4. Go through each character in the given string.
 * 5. Check if the array has space left to add new elements, if no then stop and return -1.
 * 6. Check if the current character in the string matches the given deliminator.
 * 7. If so then cut out the section of the string starting from the last deliminator or the begginning of the string
 *      and go to the current detected deliminator.
 * 8. Check if the current character is the last character in the string.
 * 9. If so then cut out the section of the string starting from the last deliminator or the begginning of the string
 *      and go to the end of the string.
 * 10. If the string has no deliminator then populate index 0 of the array with the entire string and return 1;
 * Parameters: input_string (string), separator (char), arr[] (string), arr_size (int).
 * Returns: The number of times the string was split.
*/
int split( string input_string, char separator, string arr[], int arr_size )
{
    // Declare variables.
    string split = "";
    int count = 0;
    int index_array = 0;

    // Checks to see if input_string is empty. If so return 0.
    if ( input_string == "" )
    {
        return 0;
    }

    // Loops through each character in input_string.
    for ( int i = 0; i < (int) input_string.length(); i++ )
    {
        // If the string can be split up more but the array is full then return -1;
        if ( index_array == arr_size )
        {
            return -1;
        }

        // Looks for the given deliminator in the string.
        if ( input_string[i] == separator )
        {
            // If the string hasn't already been split and this is the first time.
            if ( index_array == 0 )
            {
                // Reset this variable to empty.
                split = "";

                // Start from beginning of string and copy each character into split until deliminator is reached.
                for ( int j = count; j < i; j++ )
                {   
                    split += input_string[j];
                }

                // Add split into the first spot in the array.
                arr[index_array] = split;

                index_array++;
                count = i; // Set count = i so that next time a split occurs it starts from the previous deliminator.
            }

            // If the string has been split before.
            else
            {
                // Reset this variable to empty.
                split = "";

                // Start from last deliminator and copy each character into split until next deliminator is reached.
                for ( int j = count+1; j < i; j++ )
                {   
                    split += input_string[j];
                }

                // Add split into the array at index = index_array.
                arr[index_array] = split;

                index_array++;
                count = i; // Set count = i so that next time a split occurs it starts from the previous deliminator.
            }
        }
        
        // If the loop has reached the end of input_string but has had previous splits.
        if ( i == (int) input_string.length() - 1 && index_array > 0 )
        {
            // Reset this variable to empty.
            split = "";

            // Start from last deliminator and copy each character into split until the end of input_string is reached.
            for ( int j = count+1; j <= i; j++ )
            {   
                split += input_string[j];
            }

            // Add split into the array at index = index_array.
            arr[index_array] = split;

            index_array++;
            count = i;
        }
    }

    // If the loop has reached the end of input_string and has never been split.
    // Return 1.
    if ( index_array == 0 )
    {
        // Adds all of input_string into the first spot in the array.
        arr[0] = input_string;

        return 1;
    }

    return index_array; // Retruns the number of times the string was split.
}
