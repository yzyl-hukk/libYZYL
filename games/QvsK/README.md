# QvsK
一个简单的益智小游戏。

游戏中有两种棋子：国王和王后。

国王与王后的移动规则与国际象棋中的规则相同，将军的规则也与国际象棋相同。

游戏规则：

首先，国王选择一个位置，放在棋盘上。

然后，王后选择一个位置，放在棋盘上。

接下来国王与王后交替行动，直到游戏结束为止。

当国王被王后将死时游戏结束。

国王不能够主动走进会被王后攻击的范围，它的目标是避免被王后将死。

而王后的目标是将死国王。

游戏分两种不同视角：

国王：

  国王可以看到自身和王后的位置，也能看到王后的攻击范围。

  国王每次移动可以选择方向，如果国王的移动是非法的，程序将会强制中断这一操作。
  
  如果移动合法，程序将忠实的执行这一操作。
  
王后：

  王后只能够看到自己的位置和攻击范围，也就是说，**王后需要在不知道国王在哪的情况下将死国王**。
  
  王后的移动更加自由，每次王后可以选择移动方向和移动距离，同样需要保证移动合法。
  