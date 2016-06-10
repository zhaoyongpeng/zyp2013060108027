<div class = "dp-highlighter bg_cpp"><div class = "bar"><div class = "tools"><b>[cpp]< / b> <a href = "#" class = "ViewSource" title = "view plain" onclick = "dp.sh.Toolbar.Command('ViewSource',this);return false;">view plain< / a><span data - mod = "popu_168"> <a href = "#" class = "CopyToClipboard" title = "copy" onclick = "dp.sh.Toolbar.Command('CopyToClipboard',this);return false;">copy< / a><div style = "position: absolute; left: 0px; top: 0px; width: 0px; height: 0px; z-index: 99;"><embed id = "ZeroClipboardMovie_2" src = "http://static.blog.csdn.net/scripts/ZeroClipboard/ZeroClipboard.swf" loop = "false" menu = "false" quality = "best" bgcolor = "#ffffff" width = "0" height = "0" name = "ZeroClipboardMovie_2" align = "middle" allowscriptaccess = "always" allowfullscreen = "false" type = "application/x-shockwave-flash" pluginspage = "http://www.macromedia.com/go/getflashplayer" flashvars = "id=2&width=0&height=0" wmode = "transparent">< / div>< / span><span data - mod = "popu_169"> <a href = "#" class = "PrintSource" title = "print" onclick = "dp.sh.Toolbar.Command('PrintSource',this);return false;">print< / a>< / span><a href = "#" class = "About" title = "?" onclick = "dp.sh.Toolbar.Command('About',this);return false;"> ? < / a>< / div>< / div><ol start = "1" class = "dp-cpp"><li class = "alt"><span><span class = "preprocessor">#include&nbsp; <iostream>< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="keyword">using< / span><span>&nbsp; < / span><span class="keyword">namespace< / span><span>&nbsp; std; &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="preprocessor">#define&nbsp; MAXPROCESS&nbsp; 50 & nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;/*��������*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="preprocessor">#define&nbsp; MAXRESOURCE&nbsp; 100 & nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;/*�����Դ��*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="datatypes">int< / span><span>&nbsp; AVAILABLE[MAXRESOURCE]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*������Դ����*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="datatypes">int< / span><span>&nbsp; MAX[MAXPROCESS][MAXRESOURCE]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*����������*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="datatypes">int< / span><span>&nbsp; ALLOCATION[MAXPROCESS][MAXRESOURCE]; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*�������*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="datatypes">int< / span><span>&nbsp; NEED[MAXPROCESS][MAXRESOURCE]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*�������*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="datatypes">int< / span><span>&nbsp; REQUEST[MAXPROCESS][MAXRESOURCE]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*������Ҫ��Դ��*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="datatypes">bool< / span><span>&nbsp; FINISH[MAXPROCESS]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*ϵͳ�Ƿ����㹻����Դ����*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="datatypes">int< / span><span>&nbsp; p[MAXPROCESS]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*��¼����*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="datatypes">int< / span><span>&nbsp; m, n; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*m������,n����Դ*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="keyword">void< / span><span>&nbsp; Init(); &nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="datatypes">bool< / span><span>&nbsp; Safe(); &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="keyword">void< / span><span>&nbsp; Bank(); &nbsp; &nbsp; < / span>< / span>< / li><li class=""><span><span class="keyword">void< / span><span>&nbsp; showdata(< / span><span class="datatypes">int< / span><span>, < / span><span class="datatypes">int< / span><span>); &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span><span class="datatypes">int< / span><span>&nbsp; main()&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>{&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; Init(); &nbsp; &nbsp; < / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; Safe(); &nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; Bank(); &nbsp; &nbsp; < / span>< / li><li class=""><span>}&nbsp; &nbsp; < / span>< / li><li class="alt"><span><span class="keyword">void< / span><span>&nbsp; Init()&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*��ʼ���㷨*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>{&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; <span class="datatypes">int< / span><span>&nbsp; i, j; &nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; cout << <span class="string">"��������̵���Ŀ:"< / span><span>; &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; cin >> m; &nbsp; &nbsp; < / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; cout << <span class="string">"��������Դ������:"< / span><span>; &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; cin >> n; &nbsp; &nbsp; < / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; cout << <span class="string">"������ÿ�������������ĸ���Դ��,����"< / span><span> << m << < / span><span class="string">"x"< / span><span> << n << < / span><span class="string">"��&nbsp;������"< / span><span> << endl; &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">for< / span><span>(i = 0; i<m;i++)&nbsp;&nbsp;</span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">for< / span><span>(j = 0; j<n;j++)&nbsp;&nbsp;</span>< / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cin >> MAX[i][j]; &nbsp; &nbsp; < / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; cout << <span class="string">"������ÿ�������ѷ���ĸ���Դ��,Ҳ����"< / span><span> << m << < / span><span class="string">"x"< / span><span> << n << < / span><span class="string">"��&nbsp;������"< / span><span> << endl; &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">for< / span><span>(i = 0; i<m;i++)&nbsp;&nbsp;</span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; {&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">for< / span><span>(j = 0; j<n;j++)&nbsp;&nbsp;</span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; {&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cin >> ALLOCATION[i][j]; &nbsp; &nbsp; < / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; NEED[i][j] = MAX[i][j] - ALLOCATION[i][j]; &nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">if< / span><span>(NEED[i][j]<0)&nbsp;&nbsp;</span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; {&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cout << <span class="string">"������ĵ�"< / span><span> << i + 1 << < / span><span class="string">"��������ӵ�еĵ�"< / span><span> << j + 1 << < / span><span class="string">"����Դ��&nbsp;����,����������:"< / span><span> << endl; &nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; j--; &nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">continue< / span><span>; &nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }&nbsp; &nbsp; < / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; }&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; cout << <span class="string">"�����������Դ���е���Ŀ:"< / span><span> << endl; &nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">for< / span><span>(i = 0; i<n;i++)&nbsp;&nbsp;</span>< / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; {&nbsp; &nbsp; < / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cin >> AVAILABLE[i]; &nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; }&nbsp; &nbsp; < / span>< / li><li class=""><span>}&nbsp; &nbsp; < / span>< / li><li class="alt"><span><span class="keyword">void< / span><span>&nbsp; Bank()&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; < / span><span class="comment">/*���м��㷨*/< / span><span>&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>{&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; <span class="datatypes">int< / span><span>&nbsp; i, cusneed, flag&nbsp; = &nbsp; 0; &nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; <span class="datatypes">char< / span><span>&nbsp; again; &nbsp; &nbsp; < / span>< / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; <span class="keyword">while< / span><span>(1)&nbsp; &nbsp; < / span>< / span>< / li><li class=""><span>&nbsp; &nbsp; &nbsp; &nbsp; {&nbsp; &nbsp; < / span>< / li><li class="alt"><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; showdata(n, m); <span class="comment">////////////////////////////////////////////////////////////////////</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<endl;&nbsp;&nbsp;</span></li><li class="alt"><span>input:&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"������Ҫ������Դ�Ľ��̺�(ע:��1�����̺�Ϊ0,��������)"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cin>>cusneed;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>&nbsp;(cusneed&nbsp;>&nbsp;m)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"û�иý��̣�����������"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">goto</span><span>&nbsp;input;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"���������������ĸ���Դ������"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<n;i++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cin>>REQUEST[cusneed][i];&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<n;i++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(REQUEST[cusneed][i]>NEED[cusneed][i])</span><span class="comment">//����û�ѡ����̵߳ĵ�i����Դ�����������̸߳���Դ���������</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"��������������������̵�������!����������!"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">goto</span><span>&nbsp;input;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(REQUEST[cusneed][i]>AVAILABLE[i])</span><span class="comment">//����û�ѡ����̵߳ĵ�i����Դ��������ϵͳ���еĵ�i����Դ������</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"�����������������ϵͳ�е���Դ��!����������!"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">goto</span><span>&nbsp;input;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<n;i++)</span><span class="comment">//������������ô����</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;AVAILABLE[i]-=REQUEST[cusneed][i];<span class="comment">//ϵͳ������Դ��ȥ�����˵�</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ALLOCATION[cusneed][i]+=REQUEST[cusneed][i];<span class="comment">//�̱߳��������Դ�����������˵�</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NEED[cusneed][i]-=REQUEST[cusneed][i];<span class="comment">//�̻߳���Ҫ����Դ��ȥ������õ���</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(Safe())</span><span class="comment">//AVAILABLE&nbsp;&nbsp;ALLOCATION&nbsp;&nbsp;NEED�䶯֮���Ƿ�ᵼ�²���ȫ</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"ͬ���������!"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">else</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"�������󱻾ܾ�!"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<n;i++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;AVAILABLE[i]+=REQUEST[cusneed][i];&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ALLOCATION[cusneed][i]-=REQUEST[cusneed][i];&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NEED[cusneed][i]+=REQUEST[cusneed][i];&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>&nbsp;(i=0;i<n;i++)&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>&nbsp;(NEED[cusneed][i]&nbsp;<=&nbsp;0)&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;flag++;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>&nbsp;(flag&nbsp;==&nbsp;n)</span><span class="comment">//����ý��̸���Դ�����������������ͷ���Դ</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>&nbsp;(i=0;i<n;i++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;AVAILABLE[i]&nbsp;+=&nbsp;ALLOCATION[cusneed][i];&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ALLOCATION[cusneed][i]&nbsp;=&nbsp;0;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NEED[cusneed][i]&nbsp;=&nbsp;0;&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"�߳�"</span><span><<cusneed<<</span><span class="string">"&nbsp;ռ�е���Դ���ͷţ�"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;flag&nbsp;=&nbsp;0;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<m;i++)</span><span class="comment">//��������Ժ󽫽��̵ı�ʶFINISH�ĳ�false</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FINISH[i]=<span class="keyword">false</span><span>;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"�������ٴ����������?���밴y/Y,���밴������"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cin>>again;&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(again==</span><span class="string">'y'</span><span>||again==</span><span class="string">'Y'</span><span>)&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">continue</span><span>;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">break</span><span>;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>}&nbsp;&nbsp;</span></li><li class=""><span><span class="datatypes">bool</span><span>&nbsp;Safe()&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="comment">/*��ȫ���㷨*/</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="datatypes">int</span><span>&nbsp;i,j,k,l=0;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="datatypes">int</span><span>&nbsp;Work[MAXRESOURCE];&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="comment">/*��������*/</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<n;i++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Work[i]=AVAILABLE[i];&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<m;i++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FINISH[i]=<span class="keyword">false</span><span>;</span><span class="comment">//FINISH��¼ÿ�������Ƿ�ȫ</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<m;i++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(j=0;j<n;j++)</span><span class="comment">//ѭ�����ҵ�i��������Ҫ�ĸ�����Դ��&nbsp;�Ƿ�&nbsp;����ϵͳ���еĶ�Ӧ����Դ��</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(NEED[i][j]>Work[j])</span><span class="comment">//��i��������Ҫ�ĵ�j����Դ��&nbsp;��&nbsp;ϵͳ���еĵ�j����Դ��</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">break</span><span>;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(j==n)</span><span class="comment">//�����i����������ĸ�����Դ����û�г���ϵͳ���еĶ�Ӧ��Դ��</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FINISH[i]=<span class="keyword">true</span><span>;</span><span class="comment">//���ý��̵�FINISH���Ϊtrue</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(k=0;k<n;k++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Work[k]+=ALLOCATION[i][k];<span class="comment">//��Work��ֵΪ&nbsp;��i�����̸����ѷ�����Դ����ϵͳ���еĶ�Ӧ��Դ��(��Ϊ���Ľ���ȫ����Դ��������ʱ�߳̽���������Դ������ϵͳ)</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;p[l++]=i;<span class="comment">//��¼���̺�</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">else</span><span class="comment">//�����������ѭ����һ������</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">continue</span><span>;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(l==m)</span><span class="comment">//�����н��̶��ܹ�����������ʱ</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"ϵͳ�ǰ�ȫ��"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"��ȫ����:"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>(i=0;i<l;i++)</span><span class="comment">//����146�е�iֵ����ʾ��Դ��������̵�˳��</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<p[i];&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if</span><span>(i!=l-1)&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"-->"</span><span>;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">""</span><span><<endl;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">return</span><span>&nbsp;</span><span class="keyword">true</span><span>;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}<span class="comment">//forѭ��</span><span>&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"ϵͳ�ǲ���ȫ��"</span><span><<endl;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">return</span><span>&nbsp;</span><span class="keyword">false</span><span>;&nbsp;&nbsp;</span></span></li><li class=""><span>}&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;</span></li><li class=""><span><span class="keyword">void</span><span>&nbsp;showdata(</span><span class="datatypes">int</span><span>&nbsp;n,</span><span class="datatypes">int</span><span>&nbsp;m)&nbsp;&nbsp;&nbsp;</span><span class="comment">//��ʾ</span><span>&nbsp;&nbsp;</span></span></li><li class="alt"><span>{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="datatypes">int</span><span>&nbsp;i,j;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<endl;&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"-------------------------------------------------------------"</span><span><<endl;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"ϵͳ���õ���Դ��Ϊ:&nbsp;&nbsp;&nbsp;&nbsp;"</span><span>;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>&nbsp;&nbsp;&nbsp;(j=0;j<n;j++)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"&nbsp;&nbsp;&nbsp;&nbsp;"</span><span><<AVAILABLE[j];&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<endl;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"�����̻���Ҫ����Դ��:"</span><span><<endl;&nbsp;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>&nbsp;&nbsp;&nbsp;(i=0;i<m;i++)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"&nbsp;&nbsp;&nbsp;&nbsp;����"</span><span><<i<<</span><span class="string">":"</span><span>;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>&nbsp;&nbsp;&nbsp;(j=0;j<n;j++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"</span><span><<NEED[i][j];&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<endl;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<endl;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"�������Ѿ��õ�����Դ��:&nbsp;&nbsp;&nbsp;&nbsp;"</span><span><<endl<<endl;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>&nbsp;&nbsp;&nbsp;(i=0;i<m;i++)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"&nbsp;&nbsp;&nbsp;&nbsp;����"</span><span><<i<<</span><span class="string">":"</span><span>;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for</span><span>&nbsp;&nbsp;&nbsp;(j=0;j<n;j++)&nbsp;&nbsp;</span></span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<<span class="string">"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"</span><span><<ALLOCATION[i][j];&nbsp;&nbsp;</span></span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<endl;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;&nbsp;&nbsp;</span></li><li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;cout<<endl;&nbsp;&nbsp;&nbsp;</span></li><li class="alt"><span>}&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></li></ol></div><pre class="cpp" name="code" style="display: none;">#include <iostream>
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
	cout << "��������̵���Ŀ:";
	cin >> m;
	cout << "��������Դ������:";
	cin >> n;
	cout << "������ÿ�������������ĸ���Դ��,����" << m << "x" << n << "�� ������" << endl;
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			cin >> MAX[i][j];
	cout << "������ÿ�������ѷ���ĸ���Դ��,Ҳ����" << m << "x" << n << "�� ������" << endl;
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			cin >> ALLOCATION[i][j];
			NEED[i][j] = MAX[i][j] - ALLOCATION[i][j];
			if (NEED[i][j]<0)
			{
				cout << "������ĵ�" << i + 1 << "��������ӵ�еĵ�" << j + 1 << "����Դ�� ����,����������:" << endl;
				j--;
				continue;
			}
		}
	}
	cout << "�����������Դ���е���Ŀ:" << endl;
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
		cout << "������Ҫ������Դ�Ľ��̺�(ע:��1�����̺�Ϊ0,��������)" << endl;
		cin >> cusneed;
		if (cusneed > m)
		{
			cout << "û�иý��̣�����������" << endl;
			goto input;
		}
		cout << "���������������ĸ���Դ������" << endl;
		for (i = 0; i<n; i++)
		{
			cin >> REQUEST[cusneed][i];
		}
		for (i = 0; i<n; i++)
		{
			if (REQUEST[cusneed][i]>NEED[cusneed][i])
			{
				cout << "��������������������̵�������!����������!" << endl;
				goto input;
			}
			if (REQUEST[cusneed][i]>AVAILABLE[i])
			{
				cout << "�����������������ϵͳ�е���Դ��!����������!" << endl;
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
			cout << "ͬ���������!" << endl;
		}
		else
		{
			cout << "�������󱻾ܾ�!" << endl;
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
			cout << "�߳�" << cusneed << " ռ�е���Դ���ͷţ�" << endl;
			flag = 0;
		}
		for (i = 0; i<m; i++)
		{
			FINISH[i] = false;
		}
		cout << "�������ٴ����������?���밴y/Y,���밴������" << endl;
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
			cout << "ϵͳ�ǰ�ȫ��" << endl;
			cout << "��ȫ����:" << endl;
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
	}//forѭ��
	cout << "ϵͳ�ǲ���ȫ��" << endl;
	return false;
}

void showdata(int n, int m)   //��ʾ
{
	int i, j;
	cout << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "ϵͳ���õ���Դ��Ϊ:    ";
	for (j = 0; j<n; j++)
		cout << "    " << AVAILABLE[j];
	cout << endl;
	cout << "�����̻���Ҫ����Դ��:" << endl;
	for (i = 0; i<m; i++)
	{
		cout << "    ����" << i << ":";

		for (j = 0; j<n; j++)
			cout << "     " << NEED[i][j];
		cout << endl;
	}

	cout << endl;
	cout << "�������Ѿ��õ�����Դ��:    " << endl << endl;

	for (i = 0; i<m; i++)
	{
		cout << "    ����" << i << ":";

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
