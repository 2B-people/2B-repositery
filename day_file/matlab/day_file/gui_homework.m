function varargout = gui_homework(varargin)
% GUI_HOMEWORK MATLAB code for gui_homework.fig
%      GUI_HOMEWORK, by itself, creates a new GUI_HOMEWORK or raises the existing
%      singleton*.
%
%      H = GUI_HOMEWORK returns the handle to a new GUI_HOMEWORK or the handle to
%      the existing singleton*.
%
%      GUI_HOMEWORK('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI_HOMEWORK.M with the given input arguments.
%
%      GUI_HOMEWORK('Property','Value',...) creates a new GUI_HOMEWORK or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before gui_homework_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to gui_homework_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help gui_homework

% Last Modified by GUIDE v2.5 10-Jul-2018 21:49:30

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @gui_homework_OpeningFcn, ...
                   'gui_OutputFcn',  @gui_homework_OutputFcn, ...
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


% --- Executes just before gui_homework is made visible.
function gui_homework_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to gui_homework (see VARARGIN)

% Choose default command line output for gui_homework
handles.output = hObject;
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes gui_homework wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = gui_homework_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.peaks=peaks(35); handles.membrane=membrane; [x,y] = meshgrid(-8:.5:8); r = sqrt(x.^2+y.^2) + eps; sinc = sin(r)./r; handles.sinc = sinc; handles.current_data = handles.peaks;
surf(handles.current_data)


% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
