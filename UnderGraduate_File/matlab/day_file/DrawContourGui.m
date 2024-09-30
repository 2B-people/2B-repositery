function varargout = DrawContourGui(varargin)
% 这个GUI DrawContours Gui可以用来在图片上绘制轮廓线
%
% 如何工作？ :
% - 运行 DrawContourGui
% - 加载一张图片
% 画线
% - 在地标点上用鼠标左键单击，例如手指顶部
% - 沿着结构移动鼠标，并使用一些右击来近似注释轮廓
% - 当您到达下一个可识别的界标点时，再次点击左键完成
% - 保存
% - 鼠标中键用于闭合轮廓分离点
% 生成的.mat文件将包含一个结构 "p"
%  p.n : 点击轮廓点的数量
%  p.x, p.y : 轮廓点的位置
%  p.I : 该图片
%  p.t : 与坐标长度相同，“0”是主要界标点，“2”只是轮廓上的简单点。
%
% 当使用LoadDataSetNiceContour.m读取时，该函数将保留主要界标点，
% 并在它们之间插入一些均匀分布的次要轮廓指标。
%
% Function written by D.Kroon University of Twente (February 2010)

% Edit the above text to modify the response to help DrawContourGui

% Last Modified by Jiang Xiang 1-Mar-2018 11:15:21

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @DrawContourGui_OpeningFcn, ...
                   'gui_OutputFcn',  @DrawContourGui_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- 在DrawContourGui可见之前执行。
function DrawContourGui_OpeningFcn(hObject, eventdata, handles, varargin)
% 该函数没有输出参数，请参见OutputFcn。
% hObject    执行回调的控件对象的句柄
% eventdata  保留 - 将在未来版本的MATLAB中定义
% handles    具有句柄和用户数据的结构（参见GUIDATA）
% varargin   DrawContourGui的命令行参数（参见VARARGIN）

% 为DrawContourGui选择默认命令行输出
handles.output = hObject;
set(hObject,'toolbar','figure')%在菜单栏显示工具条内容

% 更新处理结构
guidata(hObject, handles);

% UIWAIT使DrawContourGui等待用户响应（请参阅UIRESUME）
% uiwait(handles.figure1);
data.handles=handles;
data.mouse_position_last=[0 0];
data.mouse_position=[0 0];
data.axes_size=[100 100];
data.Image=0;
data.npoints=0;
data.handleblueline=nan;
data.pointx=0;
data.pointy=0;
data.pointt=0;
setMyData(data);

% --- 这个函数的输出返回到命令行。
function varargout = DrawContourGui_OutputFcn(hObject, eventdata, handles) 
% varargout  用于返回输出参数的单元数组（参见VARARGOUT）;
% hObject    执行回调的控件对象的句柄
% eventdata  保留 - 将在未来版本的MATLAB中定义
% handles    具有句柄和用户数据的结构（参见GUIDATA）

% 从句柄结构获取默认的命令行输出
varargout{1} = handles.output;


% --------------------------------------------------------------------
function menu_file_Callback(hObject, eventdata, handles)
% hObject    句柄menu_file（请参阅GCBO）
% eventdata  保留 - 将在未来版本的MATLAB中定义
% handles    具有句柄和用户数据的结构（参见GUIDATA）


% --------------------------------------------------------------------
function menu_load_Callback(hObject, eventdata, handles)
% hObject    句柄menu_load（请参阅GCBO）
% eventdata  保留 - 将在未来版本的MATLAB中定义
% handles    具有句柄和用户数据的结构（参见GUIDATA）
[filename, pathname] = uigetfile({'*.jpg', 'JPG';'*.png', 'PNG';'*.*', 'All files (*.*)'});
if isequal(filename,0) || isequal(pathname,0)
    disp('no valid file selected');
    return;
end
data=getMyData();
data.Image=im2double(imread(fullfile(pathname, filename)));
[fx,fy]=gradient(data.Image);
data.Speedmap=mean(fx.^2+fy.^2,3);
setMyData(data);
display_photo()


function display_photo()
data=getMyData();
imshow(data.Image);   
hold on;
data.axes_size=get(data.handles.axes1,'PlotBoxAspectRatio');
set(get(data.handles.axes1,'Children'),'ButtonDownFcn','DrawContourGui(''axes1_ButtonDownFcn'',gcbo,[],guidata(gcbo))');
setMyData(data);

    

% --------------------------------------------------------------------
function menu_save_Callback(hObject, eventdata, handles)
% hObject    句柄menu_save（请参阅GCBO）
% eventdata  保留 - 将在未来版本的MATLAB中定义
% handles    具有句柄和用户数据的结构（参见GUIDATA）
data=getMyData();
p.n=data.npoints;  
p.x=data.pointx;   
p.y=data.pointy;   
p.t=data.pointt;   
p.I=data.Image;    
uisave('p');


function setMyData(data)
% 在图中存储数据结构
setappdata(gcf,'data2d',data);

function data=getMyData()
% 获取图中存储的数据结构
data=getappdata(gcf,'data2d');


% --- 在图片上执行鼠标移动 - 除了标题和菜单。
function figure1_WindowButtonMotionFcn(hObject, eventdata, handles)
% hObject    执行回调的控件对象的句柄（见GCBO）
% eventdata  保留 - 将在未来版本的MATLAB中定义
% handles    具有句柄和用户数据的结构（参见GUIDATA）
cursor_position_in_axes(hObject,handles);
data=getMyData(); if(isempty(data)), return, end
if(data.npoints>0)
    pos=data.mouse_position.*[size(data.Image,2) size(data.Image,1)];
    pointx1=data.pointx(data.npoints); pointy1=data.pointy(data.npoints);
    pointx2=pos(2); pointy2=pos(1);
    if(ishandle(data.handleblueline))
        delete(data.handleblueline)
    end
    data.handleblueline=plot([pointy1 pointy2],[pointx1 pointx2],'b');
    set(data.handleblueline,'ButtonDownFcn','DrawContourGui(''axes1_ButtonDownFcn'',gcbo,[],guidata(gcbo))');
end
setMyData(data); 


function cursor_position_in_axes(hObject,handles)
data=getMyData(); if(isempty(data)), return, end;
data.mouse_position_last=data.mouse_position;
% 获取鼠标在大轴上的位置
% p = get(0, 'PointerLocation');
% pf = get(hObject, 'pos');
% p(1:2) = p(1:2)-pf(1:2);
% set(gcf, 'CurrentPoint', p(1:2));
p = get(handles.axes1, 'CurrentPoint');
data.mouse_position=[p(1, 1) p(1, 2)]./data.axes_size(1:2);
setMyData(data);


% --- 当figure1被调整大小时执行。
function figure1_ResizeFcn(hObject, eventdata, handles)
% hObject    句柄 figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- 在坐标轴下点击鼠标执行
function axes1_ButtonDownFcn(hObject, eventdata, handles)
% hObject    句柄 axes1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
data=getMyData();
pos=data.mouse_position.*[size(data.Image,2) size(data.Image,1)];
data.mouse_button=get(handles.figure1,'SelectionType');
disp([data.mouse_button ' click']);
switch(data.mouse_button)
    case 'normal'            %左键
        plot(pos(1),pos(2),'r.');
        type=0;
    case 'extend'            %中键 (作为中断信号)
        plot(pos(1),pos(2),'b.');
        type=1;
    case 'alt'               %右键    
        plot(pos(1),pos(2),'g.');
        type=2;
    case 'open'
    otherwise
end
data.npoints=data.npoints+1;
data.pointx(data.npoints)=pos(2);
data.pointy(data.npoints)=pos(1);
data.pointt(data.npoints)=type;
setMyData(data);

