# 說明

這是一個Facebook的點名程式，主要是為了[HPXTN 台南讀書會](https://www.facebook.com/groups/tainanbookclub)的點名活動而設計的。

# 安裝

用git clone來取得source code，到```<git repo path>\fbSignIn```目錄底下，可以看見下列的檔案。

## 檔案介紹
1. main.exe  主程式
2. members.txt  社團成員名單(需手動貼上)
3. removeList.txt 沒有參加點名的名單
4. signIn.txt 點名討論串(需手動貼上)
5. result.txt 有參加點名的名單
6. checkSignIn.bat 執行取得已點名名單
7. findRemoveList.bat 執行取得移除名單

# 使用方式

1. 討論串(點名串)的所有的內容(包含發文者)，對它選取、複製，直接貼到signIn.txt。
2. 社團內的成員所有人，對它選取、複製，直接貼到members.txt。
3. 執行程式 
 - 如果你要「有效點名的名單」 執行checkSignIn.bat
 - 如果你要「沒來點名的人」執行findRemoveList.bat
4. 看結果
 -  有效點名的名單，看 result.txt
 -  沒來點名的人，看 removeList.txt
