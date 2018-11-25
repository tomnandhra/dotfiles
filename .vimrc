" Misc
set autoread
set hidden
set list listchars=tab:\ \ ,trail:·
set scrolloff=5
" if has('gui_running')
"     set guifont=FuraCode\ Nerd\ Font
" endif
set guifont=Font\ Awesome\ 14
set encoding=utf-8



" set numbering
set relativenumber
set number

" set indentation
set autoindent
set smartindent
set tabstop=4
set softtabstop=4
filetype indent on
filetype plugin indent on

" remap keys
nnoremap j gj
nnoremap k gk
nnoremap gV `[v`]
let mapleader=";"
nnoremap <leader>s :mksession<CR>
vnoremap <C-c> "*Y :let @+=@*<CR>
map <C-p> "+P

" text rendering
set encoding=utf-8
syntax enable
set wrap

" UI
set laststatus=2
set ruler
set wildmenu
set lazyredraw
set cursorline
set visualbell
set mouse=a
set title
set showmode
set showcmd
set background=dark
colorscheme dracula

" Folding
set foldmethod=indent
set foldenable
nnoremap <space> za

" search settings
set incsearch
set hlsearch
set ignorecase
set smartcase
nnoremap <leader><space> :nohlsearch<CR>

" vundle
set nocompatible
filetype off
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
"plugins:
Plugin 'VundleVim/Vundle.vim'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
Plugin 'junegunn/goyo.vim'
" Plugin 'Valloric/YouCompleteMe'
Plugin 'xuhdev/vim-latex-live-preview'
Plugin 'scrooloose/nerdtree'
" Plugin 'limelight.vim'
" Plugin 'rust-lang/rust.vim'
" Plugin 'phildawes/racer'
Plugin 'ryanoasis/vim-devicons'
call vundle#end()            " required
filetype plugin indent on    " required

" airline
" let g:airline_theme='wombat'
" let g:airline_powerline_fonts = 1
" let g:airline_left_sep = ''
" let g:airline_left_alt_sep = ''
" let g:airline_right_sep = ''
" let g:airline_right_alt_sep = ''

