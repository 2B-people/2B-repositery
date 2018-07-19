function varargout = DrawContourGui(varargin)
% ���GUI DrawContours Gui����������ͼƬ�ϻ���������
%
% ��ι����� :
% - ���� DrawContourGui
% - ����һ��ͼƬ
% ����
% - �ڵر������������������������ָ����
% - ���Žṹ�ƶ���꣬��ʹ��һЩ�һ�������ע������
% - ����������һ����ʶ��Ľ���ʱ���ٴε��������
% - ����
% - ����м����ڱպ����������
% ���ɵ�.mat�ļ�������һ���ṹ "p"
%  p.n : ��������������
%  p.x, p.y : �������λ��
%  p.I : ��ͼƬ
%  p.t : �����곤����ͬ����0������Ҫ���㣬��2��ֻ�������ϵļ򵥵㡣
%
% ��ʹ��LoadDataSetNiceContour.m��ȡʱ���ú�����������Ҫ���㣬
% ��������֮�����һЩ���ȷֲ��Ĵ�Ҫ����ָ�ꡣ
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


% --- ��DrawContourGui�ɼ�֮ǰִ�С�
function DrawContourGui_OpeningFcn(hObject, eventdata, handles, varargin)
% �ú���û�������������μ�OutputFcn��
% hObject    ִ�лص��Ŀؼ�����ľ��
% eventdata  ���� - ����δ���汾��MATLAB�ж���
% handles    ���о�����û����ݵĽṹ���μ�GUIDATA��
% varargin   DrawContourGui�������в������μ�VARARGIN��

% ΪDrawContourGuiѡ��Ĭ�����������
handles.output = hObject;
set(hObject,'toolbar','figure')%�ڲ˵�����ʾ����������

% ���´���ṹ
guidata(hObject, handles);

% UIWAITʹDrawContourGui�ȴ��û���Ӧ�������UIRESUME��
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

% --- ���������������ص������С�
function varargout = DrawContourGui_OutputFcn(hObject, eventdata, handles) 
% varargout  ���ڷ�����������ĵ�Ԫ���飨�μ�VARARGOUT��;
% hObject    ִ�лص��Ŀؼ�����ľ��
% eventdata  ���� - ����δ���汾��MATLAB�ж���
% handles    ���о�����û����ݵĽṹ���μ�GUIDATA��

% �Ӿ���ṹ��ȡĬ�ϵ����������
varargout{1} = handles.output;


% --------------------------------------------------------------------
function menu_file_Callback(hObject, eventdata, handles)
% hObject    ���menu_file�������GCBO��
% eventdata  ���� - ����δ���汾��MATLAB�ж���
% handles    ���о�����û����ݵĽṹ���μ�GUIDATA��


% --------------------------------------------------------------------
function menu_load_Callback(hObject, eventdata, handles)
% hObject    ���menu_load�������GCBO��
% eventdata  ���� - ����δ���汾��MATLAB�ж���
% handles    ���о�����û����ݵĽṹ���μ�GUIDATA��
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
% hObject    ���menu_save�������GCBO��
% eventdata  ���� - ����δ���汾��MATLAB�ж���
% handles    ���о�����û����ݵĽṹ���μ�GUIDATA��
data=getMyData();
p.n=data.npoints;  
p.x=data.pointx;   
p.y=data.pointy;   
p.t=data.pointt;   
p.I=data.Image;    
uisave('p');


function setMyData(data)
% ��ͼ�д洢���ݽṹ
setappdata(gcf,'data2d',data);

function data=getMyData()
% ��ȡͼ�д洢�����ݽṹ
data=getappdata(gcf,'data2d');


% --- ��ͼƬ��ִ������ƶ� - ���˱���Ͳ˵���
function figure1_WindowButtonMotionFcn(hObject, eventdata, handles)
% hObject    ִ�лص��Ŀؼ�����ľ������GCBO��
% eventdata  ���� - ����δ���汾��MATLAB�ж���
% handles    ���о�����û����ݵĽṹ���μ�GUIDATA��
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
% ��ȡ����ڴ����ϵ�λ��
% p = get(0, 'PointerLocation');
% pf = get(hObject, 'pos');
% p(1:2) = p(1:2)-pf(1:2);
% set(gcf, 'CurrentPoint', p(1:2));
p = get(handles.axes1, 'CurrentPoint');
data.mouse_position=[p(1, 1) p(1, 2)]./data.axes_size(1:2);
setMyData(data);


% --- ��figure1��������Сʱִ�С�
function figure1_ResizeFcn(hObject, eventdata, handles)
% hObject    ��� figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- ���������µ�����ִ��
function axes1_ButtonDownFcn(hObject, eventdata, handles)
% hObject    ��� axes1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
data=getMyData();
pos=data.mouse_position.*[size(data.Image,2) size(data.Image,1)];
data.mouse_button=get(handles.figure1,'SelectionType');
disp([data.mouse_button ' click']);
switch(data.mouse_button)
    case 'normal'            %���
        plot(pos(1),pos(2),'r.');
        type=0;
    case 'extend'            %�м� (��Ϊ�ж��ź�)
        plot(pos(1),pos(2),'b.');
        type=1;
    case 'alt'               %�Ҽ�    
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

