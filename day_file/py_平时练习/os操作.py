import os
def rename_file(name):
    file_list = os.listdir(name)
    #print(file_list)
    saved_path = os.getcwd()
    print("current working directory is"+saved_path)
    os.chdir(name)
    for file_name in file_list:
        print("old name - "+file_name)
        print("new name - "+file_name.translate(None,"0123456789"))
        os.rename(file_name,file_name.translate(None,"0123456789"))
    os.chdir(saved_path)


rename_file("r'c:\oop\prank'")