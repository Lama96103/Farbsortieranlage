   M S B A M L   `   `   `  ����L  HFarbsortierungHMI, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null5clr-namespace:FarbsortierungHMIFarbsortierungHMI  5   	   "    FarbsortierungHMI.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   1localclr-namespace:FarbsortierungHMI     5   	     � Title$  Farbsortierung��5   	   $	��450��6    $	��800��6-   $	��Top=�69   .��5	      ]� .+�5
   
   `� $	��Top=�6   .�5      c� .@�5      �� -   5        .��5   .   	Connect67   5      5      �� 5   
   $
��Info��6   $��Bottom=�6"   .��5      � $��10q�6    � RowDefinitions 5      �� 5      $
��Auto �6$   �� 5      $
��Auto �6$   �� 5      $
��Auto �6$   �� 5      $
��Auto �6$    � ColumnDefinitions 5      �� 5      $��75 �6'   �� 5      $��50 �6'   .+�5      �� $��0��6   $��0��6)   $��5q�69   Port6J   �� 5      -   5        $��ports��5   9   $��0��6   $��1��6)   $��5q�6F   null6W   �� 5      $��1��6   $��0��6)   $��5q�69   
BaudRate6N   �� 5      -   5        $��rates��5   9   $��1��6   $��1��6)   $��5q�6F   null6W   �� 5      $��2��6   $��0��6)   $��5q�69   IsConnected6Q   �� 5       -   5        $��	connected��5    9   $��2��6   $��1��6)   $��5q�6J   false6\   �� 5!      -   5        $
��send��5!   6   $��3��6   $��1��6&   $��Bottom=�6B   .��6m   
Send Hallo6y   5"      5#      5%      5&      