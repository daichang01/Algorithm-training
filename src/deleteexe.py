import os


def delete_exe_files(folder_path):
## 遍历文件夹下的所有文件
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            if file.endswith(".exe"):
                file_path = os.path.join(root, file)
                try:
                    os.remove(file_path)
                    print(f"deleted:{file_path}")
                except Exception as e:
                    print(f"error deleting {file_path}:{e}")


folder_path = "./src"
delete_exe_files(folder_path)