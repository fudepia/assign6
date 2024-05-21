# Programming Assignment #6

**Due:2024/5/28 23:59:59**

NCCU OOP 112 spring

author: @organic_san at 2024/4/29

---

## Topic: 建立一個控制台的RPG遊戲(Part 2)
## Objective: 熟悉 OOP 概念與多檔案之間的操作

## Description

### 遊戲目標
使用控制台建立一個RPG的小遊戲，包含進入遊戲、移動、切換房間，以及戰鬥、收尾等流程。

在進入遊戲之後，遊戲會來到以35 * 20的格子單位所建構成的房間，也就是遊戲中的地圖。玩家可以使用WASD進行前後左右的操作，操作名為「PL」的玩家圖示進行在房間中前後左右的移動，並且會受到牆壁的阻擋。

透過來到房間的左右側進行房間的切換，其中本次作業只考慮左右之間的地圖切換，不考慮上下之間的房間切換。房間透過 `id` 彼此左右連接，最左邊為0號的房間，每往右側的房間，房間`id`會+1，往左側的房間時，房間id會-1。但是不能前往資料不存在的房間。

遊戲中會出現有自我移動方式的敵人，需要設計怪物的移動模式。在遭遇怪物之後，將會進入戰鬥模式，此時玩家可以做出從選單中選擇以下四種操作：攻擊、防禦、猛力一擊、以及回複，詳細的差異將於後續作業中說明。

如果被怪物擊倒，將進入遊戲結束狀態，而怪物可以設定成最終boss，擊倒有最終boss標記的敵人時，則將進入遊戲過關狀態。

完整版本的遊戲試玩可以執行這個程式：<br>
`./example/rpg-game-full-example`

### 本次作業目標

本次作業的目標是完成左右房間的切換，以及怪物的移動系統。當玩家「PL」來到房間的左右邊緣時，如果不是最左或最右的邊緣，則向左邊或右邊的房間移動，並且切換玩家所在位置到房間的另一端。怪物繼承自新的class：Enemy，不同的enemy有不同的主動移動方法。在本次作業中還不會加入遊戲戰鬥的環節。

關於enemy的設計細節如下：

- Slime:
  - 在每幀時，在地圖中朝上、下、左、右四個方向隨機移動
  - 不會移動到不能移動的方塊(定義在Room::walkable())
  - 5滴血量，攻擊力1
- Dragon:
  - 不會移動
  - 30滴血量，攻擊力3

在本次作業中，主要以物件繼承利用，以及class、function的設計為主。

render的部分已包含在作業檔案中，不需處理輸出處理的排版部分。

### 需要完成的內容
- 請根據這個 git 記錄中的 `assign 5 code` 的 commit (dbcf521f) 和 `assign 6 code` 的 commit (931e42ef) 的差異，更新您完成的 assign5 的完成版。
  具體而言，請根據 github 上的[這個網址](https://github.com/oopnccucs/assign6/commit/931e42efd53d95a5db1edb9f5411fad3b266d392)進行比較，或是使用 `$git checkout <commit-hash>` 進行commit間的切換與比較。

- 完成 `Enemy` class、 `Slime` class 、 `Dragon` class，使用繼承管理這三者與 `GameObject` class 的關係
- 完成 `room` 中關於 `Enemy` 使用的處理
- 完成 `controller` 中PL移動與房間切換的邏輯處理
- 在 `controller` 中加入怪物主動移動的邏輯處理


## Sample Output
請參見 `./example/rpg-game-part2-example` 的執行結果，若順利的話會出現以下圖片：

![pic](https://i.imgur.com/lhKgeVc.png)

其中`WW`代表草地，`██`代表牆壁，`DR`代表門，`PL`代表角色。

場地物件的名稱與種類記錄在 `./src/gameobjects/room/roomstate.h` 中。

移動到房間的右側邊緣可以移動到第二個房間，當移動到第二個房間時，會出現如下結果：

![pic](https://i.imgur.com/9By0Wzi.png)

其中`WW`代表草地，`▲▲`代表山岩，`==`代表史萊姆，`PL`代表角色。

史萊姆會在每一幀往隨機方向前進一格，不會受到草地的阻擋，會受到山岩的阻擋。目前當玩家與史萊姆重疊的時候，尚不進行處理。

移動到第三個房間時，會出現如下結果：

![pic](https://i.imgur.com/vpGXOVT.png)

其中`██`代表牆壁，`▲▲`代表山岩，`DR`代表門，`Dn`代表龍，`PL`代表角色，`~~`或`……`代表水。

龍不會移動。目前當玩家與龍重疊的時候，尚不進行處理。


## 評分標準
| 評分標準 | 分數 |
| - | - |
| 上傳檔案 | 20分 |
| 可以編譯 | 15分 |
| 人物(PL)可以切換房間 | 15分 |
| 人物(PL)在切換房間的過程中沒有任何問題 | 10分 |
| Enemy會顯示在房間中 | 10分 |
| Slime的移動模式與規則相同 | 15分 |
| Slime的移動會受到地形阻擋影響 | 15分 |
| **合計** | **100分** |


## Assignment Directory
`/usr/local/class/oop/assign/assign6`
or https://github.com/oopnccucs/assign6


## 作業繳交方式
在OOP主機中，assign6資料夾下，輸入：
```
/usr/local/class/oop/bin/submit 6
```
繳交本次作業。


## Files in the Assignment Directory

- `./src/main.cpp`: <br>
  處理進入遊戲之後，將調整控制台模式並捕捉鍵盤輸入，定時呼叫 `game.lifeCycle(action)` 建立遊戲迴圈，而輸入的內容在經過處理之後成為遊戲的每幀進入點。

- `./src/gamecore`: <br>
  用於處理遊戲外部操作接收的class。

- `./src/functions`:<br>
  包含 `AnsiPrint` 與 `position` 。

- `./src/controller`:<br>
  用於處理遊戲內中反應的部分，其中 `run()` 函數會由 `gamecore` 呼叫，是遊戲主要循環的函數，會在每幀執行一次。<br>
  在這次的作業中需要完成房間的切換，以及怪物的移動。

  - `enviroment`:<br>
    儲存了遊戲中的環境變數。其中 `SPEED` 為每幀秒數(s)。

- `./src/gameobjects`:<br>
  主要處理遊戲物件的反應，其中包含 `player` 、 `room` 與 `gameobject` 。

  - `player`:<br>
    繼承了 `GameObject` class。

  - `enemy`:<br>
    繼承了 `GameObject` class，需要完成相關函數。

  - `slime` 與 `dragon`:<br>
    繼承了 `Enemy` class，需要完成相關函數。

  - `room`:<br>
    包含遊戲的房間內容，以及相關的行為處理。`Room` class 是單一個房間的 class，請完成 `Enemy` 相關處理的部分。

  - `gameobject`:<br>
    包含遊戲物件的基本定義。

- `./src/gameprocess`:<br>
  目前記錄了關於遊戲進程狀態的 struct，在後續作業中會逐漸追加狀態種類。


## Implementation Notes

編譯:`$make`

執行: `$make run`

作業的完成方法不一定要拘泥於提供的方法，只要能得到類似的結果都沒問題。但是物件的繼承關係與呼叫需要遵照所提供的方式處理。