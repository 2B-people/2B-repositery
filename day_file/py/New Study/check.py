#coding :utf-8

def read_text():
    quotes = open("")
    contents_of_flie = quotes.read()
    print(contents_of_file)
    quotes.close()


def check_profanity(test_to_check):
    connection = urllib.urlopen("http://www.wdylike.appspot.com/?q=shot"+test_to_check)
    output = connection.read()
    #print(output)
    connection.close()
    if "true" in output:
        print("Profanity Alert!!")
    elif "false" in output:
        print("This document has no  curse words!")
    else:
        print("Could not scan the document properly.")

    
read_text()
check_profanity()