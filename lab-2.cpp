<div class = "dp-highlighter bg_cpp"><div class = "bar"><div class = "tools"><b>[cpp]< / b> <a href = "#" class = "ViewSource" title = "view plain" onclick = "dp.sh.Toolbar.Command('ViewSource',this);return false;">view plain< / a><span data - mod = "popu_168"> <a href = "#" class = "CopyToClipboard" title = "copy" onclick = "dp.sh.Toolbar.Command('CopyToClipboard',this);return false;">copy< / a><div style = "position: absolute; left: 0px; top: 0px; width: 0px; height: 0px; z-index: 99;"><embed id = "ZeroClipboardMovie_2" src = "http://static.blog.csdn.net/scripts/ZeroClipboard/ZeroClipboard.swf" loop = "false" menu = "false" quality = "best" bgcolor = "#ffffff" width = "0" height = "0" name = "ZeroClipboardMovie_2" align = "middle" allowscriptaccess = "always" allowfullscreen = "false" type = "application/x-shockwave-flash" pluginspage = "http://www.macromedia.com/go/getflashplayer" flashvars = "id=2&width=0&height=0" wmode = "transparent">< / div>< / span><span data - mod = "popu_169"> <a href = "#" class = "PrintSource" title = "print" onclick = "dp.sh.Toolbar.Command('PrintSource',this);return false;">print< / a>< / span><a href = "#" class = "About" title = "?" onclick = "dp.sh.Toolbar.Command('About',this);return false;"> ? < / a>< / div>< / div><ol start = "1" class = "dp-cpp"><li class = "alt"><span><span class = "preprocessor">#include&nbsp; <iostream>< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="keyword">using< / span><span>&nbsp; < / span><span class="keyword">namespace< / span><span>&nbsp; std; &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="preprocessor">#define&nbsp; MAXPROCESS&nbsp; 50 & nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;/*最大进程数*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="preprocessor">#define&nbsp; MAXRESOURCE&nbsp; 100 & nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;/*最大资源数*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="datatypes">int< / span><span>&nbsp; AVAILABLE[MAXRESOURCE]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*可用资源数组*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="datatypes">int< / span><span>&nbsp; MAX[MAXPROCESS][MAXRESOURCE]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*最大需求矩阵*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="datatypes">int< / span><span>&nbsp; ALLOCATION[MAXPROCESS][MAXRESOURCE]; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*分配矩阵*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="datatypes">int< / span><span>&nbsp; NEED[MAXPROCESS][MAXRESOURCE]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*需求矩阵*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="datatypes">int< / span><span>&nbsp; REQUEST[MAXPROCESS][MAXRESOURCE]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*进程需要资源数*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="datatypes">bool< / span><span>&nbsp; FINISH[MAXPROCESS]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*系统是否有足够的资源分配*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="datatypes">int< / span><span>&nbsp; p[MAXPROCESS]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*记录序列*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="datatypes">int< / span><span>&nbsp; m, n; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*m个进程,n个资源*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="keyword">void< / span><span>&nbsp; Init(); &nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="datatypes">bool< / span><span>&nbsp; Safe(); &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="keyword">void< / span><span>&nbsp; Bank(); &nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="keyword">void< / span><span>&nbsp; showdata(< / span><span class="datatypes">int< / span><span>, < / span><span class="datatypes">int< / span><span>); &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="datatypes">int< / span><span>&nbsp; main()&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>{&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; Init(); &nbsp; &nbsp; < / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; Safe(); &nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; Bank(); &nbsp; &nbsp; < / span>< / li><li class=""><span>}&nbsp; &nbsp; < / span>< / li><li class="alt"><span><span class="keyword">void< / span><span>&nbsp; Init()&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*初始化算法*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>{&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; <span class="datatypes">int< / span><span>&nbsp; i, j; &nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; cout << <span class="string">"请输入进程的数目:"< / span><span>; &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; cin >> m; &nbsp; &nbsp; < / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; cout << <span class="string">"请输入资源的种类:"< / span><span>; &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; cin >> n; &nbsp; &nbsp; < / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; cout << <span class="string">"请输入每个进程最多所需的各资源数,按照"< / span><span> << m << < / span><span class="string">"x"< / span><span> << n << < / span><span class="string">"矩&nbsp;阵输入"< / span><span> << endl; &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">for< / span><span>(i = 0; i<m;i++)&nbsp;&nbsp;</span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">for< / span><span>(j = 0; j<n;j++)&nbsp;&nbsp;</span>< / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cin >> MAX[i][j]; &nbsp; &nbsp; < / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; cout << <span class="string">"请输入每个进程已分配的各资源数,也按照"< / span><span> << m << < / span><span class="string">"x"< / span><span> << n << < / span><span class="string">"矩&nbsp;阵输入"< / span><span> << endl; &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">for< / span><span>(i = 0; i<m;i++)&nbsp;&nbsp;</span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; {&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">for< / span><span>(j = 0; j<n;j++)&nbsp;&nbsp;</span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; {&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cin >> ALLOCATION[i][j]; &nbsp; &nbsp; < / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; NEED[i][j] = MAX[i][j] - ALLOCATION[i][j]; &nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">if< / span><span>(NEED[i][j]<0)&nbsp;&nbsp;</span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; {&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cout << <span class="string">"您输入的第"< / span><span> << i + 1 << < / span><span class="string">"个进程所拥有的第"< / span><span> << j + 1 << < / span><span class="string">"个资源数&nbsp;错误,请重新输入:"< / span><span> << endl; &nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; j--; &nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">continue< / span><span>; &nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }&nbsp; &nbsp; < / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; }&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; cout << <span class="string">"请输入各个资源现有的数目:"< / span><span> << endl; &nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">for< / span><span>(i = 0; i<n;i++)&nbsp;&nbsp;</span>< / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; {&nbsp; &nbsp; < / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cin >> AVAILABLE[i]; &nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; }&nbsp; &nbsp; < / span>< / li><li class=""><span>}&nbsp; &nbsp; < / span>< / li><li class="alt"><span><span class="keyword">void< / span><span>&nbsp; Bank()&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*银行家算法*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>{&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; <span class="datatypes">int< / span><span>&nbsp; i, cusneed, flag&nbsp; = &nbsp; 0; &nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; <span class="datatypes">char< / span><span>&nbsp; again; &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">while< / span><span>(1)&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; {&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; showdata(n, m); <span class="comment">////////////////////////////////////////////////////////////////////</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<endl;&nbsp;&nbsp;</span></li><li class="alt"><span>input:&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"请输入要申请资源的进程号(注:第1个进程号为0,依次类推)"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cin>>cusneed;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>&nbsp;(cusneed&nbsp;>&nbsp;m)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"没有该进程，请重新输入"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">goto</span><span>&nbsp;input;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"请输入进程所请求的各资源的数量"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<n;i++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cin>>REQUEST[cusneed][i];&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<n;i++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(REQUEST[cusneed][i]>NEED[cusneed][i])</span><span class="comment">//如果用户选择的线程的第i个资源请求数＞该线程该资源所需的数量</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"您输入的请求数超过进程的需求量!请重新输入!"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">goto</span><span>&nbsp;input;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(REQUEST[cusneed][i]>AVAILABLE[i])</span><span class="comment">//如果用户选择的线程的第i个资源请求数＞系统现有的第i个资源的数量</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"您输入的请求数超过系统有的资源数!请重新输入!"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">goto</span><span>&nbsp;input;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<n;i++)</span><span class="comment">//如果请求合理，那么下面</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;AVAILABLE[i]-=REQUEST[cusneed][i];<span class="comment">//系统可用资源减去申请了的</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ALLOCATION[cusneed][i]+=REQUEST[cusneed][i];<span class="comment">//线程被分配的资源加上已申请了的</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NEED[cusneed][i]-=REQUEST[cusneed][i];<span class="comment">//线程还需要的资源减去已申请得到的</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(Safe())</span><span class="comment">//AVAILABLE&nbsp;&nbsp;ALLOCATION&nbsp;&nbsp;NEED变动之后，是否会导致不安全</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"同意分配请求!"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">else</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"您的请求被拒绝!"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<n;i++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;AVAILABLE[i]+=REQUEST[cusneed][i];&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ALLOCATION[cusneed][i]-=REQUEST[cusneed][i];&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NEED[cusneed][i]+=REQUEST[cusneed][i];&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>&nbsp;(i=0;i<n;i++)&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>&nbsp;(NEED[cusneed][i]&nbsp;<=&nbsp;0)&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;flag++;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>&nbsp;(flag&nbsp;==&nbsp;n)</span><span class="comment">//如果该进程各资源都已满足条件，则释放资源</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>&nbsp;(i=0;i<n;i++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;AVAILABLE[i]&nbsp;+=&nbsp;ALLOCATION[cusneed][i];&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ALLOCATION[cusneed][i]&nbsp;=&nbsp;0;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NEED[cusneed][i]&nbsp;=&nbsp;0;&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"线程"</span><span><<cusneed<<</span><span class="string">"&nbsp;占有的资源被释放！"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;flag&nbsp;=&nbsp;0;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<m;i++)</span><span class="comment">//分配好了以后将进程的标识FINISH改成false</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FINISH[i]=<span class="keyword">false</span><span>;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"您还想再次请求分配吗?是请按y/Y,否请按其它键"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cin>>again;&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(again==</span><span class="string">'y'</span><span>||again==</span><span class="string">'Y'</span><span>)&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">continue</span><span>;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">break</span><span>;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>}&nbsp;&nbsp;</span></li><li class=""><span><span class="datatypes">bool</span><span>&nbsp;Safe()&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="comment">/*安全性算法*/</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="datatypes">int</span><span>&nbsp;i,j,k,l=0;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="datatypes">int</span><span>&nbsp;Work[MAXRESOURCE];&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="comment">/*工作数组*/</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<n;i++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Work[i]=AVAILABLE[i];&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<m;i++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FINISH[i]=<span class="keyword">false</span><span>;</span><span class="comment">//FINISH记录每个进程是否安全</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<m;i++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(j=0;j<n;j++)</span><span class="comment">//循环查找第i个进程需要的各个资源数&nbsp;是否&nbsp;超过系统现有的对应的资源数</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(NEED[i][j]>Work[j])</span><span class="comment">//第i个进程需要的第j个资源数&nbsp;＞&nbsp;系统现有的第j个资源数</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">break</span><span>;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(j==n)</span><span class="comment">//如果第i个进程所需的各个资源数都没有超过系统现有的对应资源数</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FINISH[i]=<span class="keyword">true</span><span>;</span><span class="comment">//给该进程的FINISH标记为true</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(k=0;k<n;k++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Work[k]+=ALLOCATION[i][k];<span class="comment">//将Work赋值为&nbsp;第i个进程各个已分配资源数＋系统现有的对应资源数(因为当改进程全部资源数都满足时线程结束并将资源返还给系统)</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;p[l++]=i;<span class="comment">//记录进程号</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">else</span><span class="comment">//如果超过继续循环下一个进程</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">continue</span><span>;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(l==m)</span><span class="comment">//当所有进程都能够被满足运行时</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"系统是安全的"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"安全序列:"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<l;i++)</span><span class="comment">//改了146行的i值，显示资源分配给进程的顺序</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<p[i];&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(i!=l-1)&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"-->"</span><span>;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">""</span><span><<endl;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">return</span><span>&nbsp;</span><span class="keyword">true</span><span>;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}<span class="comment">//for循环</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"系统是不安全的"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">return</span><span>&nbsp;</span><span class="keyword">false</span><span>;&nbsp;&nbsp;</span></span></li><li class=""><span>}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;</span></li><li class=""><span><span class="keyword">void</span><span>&nbsp;showdata(</span><span class="datatypes">int</span><span>&nbsp;n,</span><span class="datatypes">int</span><span>&nbsp;m)&nbsp;&nbsp;&nbsp;</span><span class="comment">//显示</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="datatypes">int</span><span>&nbsp;i,j;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<endl;&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"-------------------------------------------------------------"</span><span><<endl;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"系统可用的资源数为:&nbsp;&nbsp;&nbsp;&nbsp;"</span><span>;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>&nbsp;&nbsp;&nbsp;(j=0;j<n;j++)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"&nbsp;&nbsp;&nbsp;&nbsp;"</span><span><<AVAILABLE[j];&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<endl;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"各进程还需要的资源量:"</span><span><<endl;&nbsp;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>&nbsp;&nbsp;&nbsp;(i=0;i<m;i++)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"&nbsp;&nbsp;&nbsp;&nbsp;进程"</span><span><<i<<</span><span class="string">":"</span><span>;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>&nbsp;&nbsp;&nbsp;(j=0;j<n;j++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"</span><span><<NEED[i][j];&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<endl;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<endl;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"各进程已经得到的资源量:&nbsp;&nbsp;&nbsp;&nbsp;"</span><span><<endl<<endl;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>&nbsp;&nbsp;&nbsp;(i=0;i<m;i++)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"&nbsp;&nbsp;&nbsp;&nbsp;进程"</span><span><<i<<</span><span class="string">":"</span><span>;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>&nbsp;&nbsp;&nbsp;(j=0;j<n;j++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"</span><span><<ALLOCATION[i][j];&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<endl;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<endl;&nbsp;&nbsp;&nbsp;</span></li><li class="alt"><span>}&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></li></ol></div><pre class="cpp" name="code" style="display: none;">#include <iostream>
	using namespace std;
#define MAXPROCESS 50                       
#define MAXRESOURCE 100                      
int AVAILABLE[MAXRESOURCE];                    
int MAX[MAXPROCESS][MAXRESOURCE];           
int ALLOCATION[MAXPROCESS][MAXRESOURCE];   
int NEED[MAXPROCESS][MAXRESOURCE];            
int REQUEST[MAXPROCESS][MAXRESOURCE];        
bool FINISH[MAXPROCESS];                        
int p[MAXPROCESS];                             
int m, n;                                   
void Init();
bool Safe();
void Bank();
void showdata(int, int);
int main()
{
	Init();
	Safe();
	Bank();
}
void Init()                
{
	int i, j;
	cout << "请输入进程的数目:";
	cin >> m;
	cout << "请输入资源的种类:";
	cin >> n;
	cout << "请输入每个进程最多所需的各资源数,按照" << m << "x" << n << "矩 阵输入" << endl;
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			cin >> MAX[i][j];
	cout << "请输入每个进程已分配的各资源数,也按照" << m << "x" << n << "矩 阵输入" << endl;
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			cin >> ALLOCATION[i][j];
			NEED[i][j] = MAX[i][j] - ALLOCATION[i][j];
			if (NEED[i][j]<0)
			{
				cout << "您输入的第" << i + 1 << "个进程所拥有的第" << j + 1 << "个资源数 错误,请重新输入:" << endl;
				j--;
				continue;
			}
		}
	}
	cout << "请输入各个资源现有的数目:" << endl;
	for (i = 0; i<n; i++)
	{
		cin >> AVAILABLE[i];
	}
}
void Bank()                
{
	int i, cusneed, flag = 0;
	char again;
	while (1)
	{
		showdata(n, m);////////////////////////////////////////////////////////////////////
		cout << endl;
	input:
		cout << "请输入要申请资源的进程号(注:第1个进程号为0,依次类推)" << endl;
		cin >> cusneed;
		if (cusneed > m)
		{
			cout << "没有该进程，请重新输入" << endl;
			goto input;
		}
		cout << "请输入进程所请求的各资源的数量" << endl;
		for (i = 0; i<n; i++)
		{
			cin >> REQUEST[cusneed][i];
		}
		for (i = 0; i<n; i++)
		{
			if (REQUEST[cusneed][i]>NEED[cusneed][i])
			{
				cout << "您输入的请求数超过进程的需求量!请重新输入!" << endl;
				goto input;
			}
			if (REQUEST[cusneed][i]>AVAILABLE[i])
			{
				cout << "您输入的请求数超过系统有的资源数!请重新输入!" << endl;
				goto input;
			}
		}
		for (i = 0; i<n; i++)
		{
			AVAILABLE[i] -= REQUEST[cusneed][i];
			ALLOCATION[cusneed][i] += REQUEST[cusneed][i];
			NEED[cusneed][i] -= REQUEST[cusneed][i];
		}
		if (Safe())
		{
			cout << "同意分配请求!" << endl;
		}
		else
		{
			cout << "您的请求被拒绝!" << endl;
			for (i = 0; i<n; i++)
			{
				AVAILABLE[i] += REQUEST[cusneed][i];
				ALLOCATION[cusneed][i] -= REQUEST[cusneed][i];
				NEED[cusneed][i] += REQUEST[cusneed][i];
			}
		}
		for (i = 0; i<n; i++)
		{
			if (NEED[cusneed][i] <= 0)
			{
				flag++;
			}
		}
		if (flag == n)
		{
			for (i = 0; i<n; i++)
			{
				AVAILABLE[i] += ALLOCATION[cusneed][i];
				ALLOCATION[cusneed][i] = 0;
				NEED[cusneed][i] = 0;
			}
			cout << "线程" << cusneed << " 占有的资源被释放！" << endl;
			flag = 0;
		}
		for (i = 0; i<m; i++)
		{
			FINISH[i] = false;
		}
		cout << "您还想再次请求分配吗?是请按y/Y,否请按其它键" << endl;
		cin >> again;
		if (again == 'y' || again == 'Y')
		{
			continue;
		}
		break;
	}
}
bool Safe()                                    
{
	int i, j, k, l = 0;
	int Work[MAXRESOURCE];                  
	for (i = 0; i<n; i++)
		Work[i] = AVAILABLE[i];
	for (i = 0; i<m; i++)
	{
		FINISH[i] = false;
	}
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (NEED[i][j]>Work[j])
			{
				break;
			}
		}
		if (j == n)
		{
			FINISH[i] = true;
			for (k = 0; k<n; k++)
			{
				Work[k] += ALLOCATION[i][k];
			}
			p[l++] = i;
		}
		else
		{
			continue;
		}
		if (l == m)
		{
			cout << "系统是安全的" << endl;
			cout << "安全序列:" << endl;
			for (i = 0; i<l; i++)//
			{
				cout << p[i];
				if (i != l - 1)
				{
					cout << "-->";
				}
			}
			cout << "" << endl;
			return true;
		}
	}//for循环
	cout << "系统是不安全的" << endl;
	return false;
}

void showdata(int n, int m)   //显示
{
	int i, j;
	cout << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "系统可用的资源数为:    ";
	for (j = 0; j<n; j++)
		cout << "    " << AVAILABLE[j];
	cout << endl;
	cout << "各进程还需要的资源量:" << endl;
	for (i = 0; i<m; i++)
	{
		cout << "    进程" << i << ":";

		for (j = 0; j<n; j++)
			cout << "     " << NEED[i][j];
		cout << endl;
	}

	cout << endl;
	cout << "各进程已经得到的资源量:    " << endl << endl;

	for (i = 0; i<m; i++)
	{
		cout << "    进程" << i << ":";

		for (j = 0; j<n; j++)
			cout << "     " << ALLOCATION[i][j];
		cout << endl;
	}
	cout << endl;
}   < / pre><br>
<p>< / p>
<pre>< / pre>
<p>< / p>
<p>< / p>
<pre>< / pre>
<p>< / p>
<p>< / p>
<pre>< / pre>
<p>< / p>
