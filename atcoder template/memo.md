# memo
### 参考
yokozuna57 

### TODO
- mod関係
- xorの基底を生成するやつ
- セグメント木？




### boost導入メモ
https://qiita.com/hitomatagi/items/ca8f4622052f9df05079
http://critter.sakura.ne.jp/memo_tech/boost_mingw.html

```powershell
.\b2.exe toolset=gcc

# # x86
# .\b2.exe toolset=msvc-14.1 link=static runtime-link=static,shared --build-dir=build/x86 address-model=32 -j5 install --includedir=C:\Nospace\boost\boost_1_77_0\include --libdir=C:\Nospace\boost\boost_1_77_0\stage\lib\x86

# # x64
# .\b2.exe toolset=msvc-14.1 link=static runtime-link=static,shared --build-dir=build/x64 address-model=64 -j5 install --includedir=C:\Nospace\boost\boost_1_77_0\include --libdirC:\Nospace\boost\boost_1_77_0\stage\lib\x64
```



