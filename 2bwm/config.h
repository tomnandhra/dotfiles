//  DEFINE SUPER KEY AS MODIFIER
#define MOD             XCB_MOD_MASK_4
/* SPEED
 1) move slow
 2) move fast
 3) mouse slow
 4) mouse fast  */
static const uint16_t movements[] = {60,120,400,400};
// RESIZE MY LINE
static const bool     resize_by_line          = true;
// RATIO FOR RESIZING AND KEEPING ASPECT
static const float    resize_keep_aspect_ratio= 1.03;
/* OFFSETS
 1) offsetx
 2) offsety
 3) maxwidth
 4) maxheight  */
static const uint8_t offsets[] = {10,40,0,18};
/* COLOURS
 1) focuscol
 2) unfocuscol
 3) fixedcol
 4) unkilcol
 5) fixedunkilcol
 6) outerbordercol
 7) emptycol
*/
static const char *colors[] = {"#35586c","#333333","#7a8c5c","#ff6666","#6272a4","#0d131a","#000000"};
static const bool inverted_colors = true;			/* if this is set to true the inner border and outer borders colors will be swapped */
/* CURSOR
 * TOP_LEFT
 * TOP_RIGHT
 * BOTTOM_LEFT
 * BOTTOM_RIGHT
 * MIDDLE  */
#define CURSOR_POSITION BOTTOM_RIGHT
/* BORDERS
 1) outer border size
 2) full borderwidth
 3) magnet border size
 4) resize border size  */
static const uint8_t borders[] = {3,5,5,4};
/* Windows that won't have a border.
 * It uses substring comparison with what is found in the WM_NAME
 * attribute of the window. You can test this using `xprop WM_NAME`
 */
#define LOOK_INTO "WM_NAME"
static const char *ignore_names[] = {"bar", "xclock"};
///--Menus and Programs---///
static const char *menucmd[]   = { "rofi", NULL };
///--Custom foo---///
static void halfandcentered(const Arg *arg)
{
	Arg arg2 = {.i=TWOBWM_MAXHALF_VERTICAL_LEFT};
	maxhalf(&arg2);
	Arg arg3 = {.i=TWOBWM_TELEPORT_CENTER};
	teleport(&arg3);
}
																												// CHANGE WORKSPACE/MOVE WINDOW TO WORKSPACE (USING NUMBERS)
																												// super + (number)			-->  change workspace
																												// super + shift + (number)	-->  move window to workspace
#define DESKTOPCHANGE(K,N) \
{  MOD ,             K,              changeworkspace, {.i=N}}, \
{  MOD |SHIFT,       K,              sendtoworkspace, {.i=N}},

static key keys[] = {																							// CHANGE FOCUS
    {  ALT ,              XK_Tab,        focusnext,         {.i=TWOBWM_FOCUS_NEXT}},							// alt + tab				-->  focus next
    {  ALT |SHIFT,        XK_Tab,        focusnext,         {.i=TWOBWM_FOCUS_PREVIOUS}},						// alt + shift + tab		-->  focus previous
																												// MODIFY WINDOWS
    {  MOD ,		      XK_q,          deletewin,         {}},												// super + q				-->  delete window
																												// MOVE CURRENTLY SELECTED WINDOW
    {  MOD ,              XK_k,          movestep,          {.i=TWOBWM_MOVE_UP}},								// super + k				-->  move up
    {  MOD ,              XK_j,          movestep,          {.i=TWOBWM_MOVE_DOWN}},                             // super + j				-->  move down
    {  MOD ,              XK_l,          movestep,          {.i=TWOBWM_MOVE_RIGHT}},                            // super + l				-->  move right
    {  MOD ,              XK_h,          movestep,          {.i=TWOBWM_MOVE_LEFT}},                             // super + h				-->  move left
    {  MOD |CONTROL,      XK_k,          movestep,          {.i=TWOBWM_MOVE_UP_SLOW}},							// super + ctrl + k			-->  move up (slow)
    {  MOD |CONTROL,      XK_j,          movestep,          {.i=TWOBWM_MOVE_DOWN_SLOW}},						// super + ctrl + j			-->  move down (slow)
    {  MOD |CONTROL,      XK_l,          movestep,          {.i=TWOBWM_MOVE_RIGHT_SLOW}},                       // super + ctrl + l			-->  move right (slow)
    {  MOD |CONTROL,      XK_h,          movestep,          {.i=TWOBWM_MOVE_LEFT_SLOW}},                        // super + ctrl + h			-->  move left (slow)
																												// RESIZE CURRENTLY SELECTED WINDOW
    {  MOD |SHIFT,        XK_k,          resizestep,        {.i=TWOBWM_RESIZE_UP}},								// super + shift + k		-->  resize up
    {  MOD |SHIFT,        XK_j,          resizestep,        {.i=TWOBWM_RESIZE_DOWN}},							// super + shift + j		-->  resize down
    {  MOD |SHIFT,        XK_l,          resizestep,        {.i=TWOBWM_RESIZE_RIGHT}},							// super + shift + l		-->  resize right
    {  MOD |SHIFT,        XK_h,          resizestep,        {.i=TWOBWM_RESIZE_LEFT}},							// super + shift + h		-->  resize left
    {  MOD |SHIFT|CONTROL,XK_k,          resizestep,        {.i=TWOBWM_RESIZE_UP_SLOW}},						// super + shift + ctrl + k	-->  resize up (slow)
    {  MOD |SHIFT|CONTROL,XK_j,          resizestep,        {.i=TWOBWM_RESIZE_DOWN_SLOW}},                      // super + shift + ctrl + j	-->  resize down (slow)
    {  MOD |SHIFT|CONTROL,XK_l,          resizestep,        {.i=TWOBWM_RESIZE_RIGHT_SLOW}},                     // super + shift + ctrl + l	-->  resize right (slow)
    {  MOD |SHIFT|CONTROL,XK_h,          resizestep,        {.i=TWOBWM_RESIZE_LEFT_SLOW}},                      // super + shift + ctrl + h	-->  resize left (slow)
    {  MOD ,              XK_Home,       resizestep_aspect, {.i=TWOBWM_RESIZE_KEEP_ASPECT_GROW}},				// super + home				-->  resize larger (while keeping window aspect ratio)
    {  MOD ,              XK_End,        resizestep_aspect, {.i=TWOBWM_RESIZE_KEEP_ASPECT_SHRINK}},				// super + end				-->  resize smaller (while keeping window aspect ratio)
																												// MOVE CURSOR
    {  MOD |SHIFT,        XK_Up,         cursor_move,       {.i=TWOBWM_CURSOR_UP}},								// super + up				-->  move cursor up
    {  MOD |SHIFT,        XK_Down,       cursor_move,       {.i=TWOBWM_CURSOR_DOWN}},							// super + down				-->  move cursor down
    {  MOD |SHIFT,        XK_Right,      cursor_move,       {.i=TWOBWM_CURSOR_RIGHT}},							// super + right			-->  move cursor right
    {  MOD |SHIFT,        XK_Left,       cursor_move,       {.i=TWOBWM_CURSOR_LEFT}},							// super + left				-->  move cursor left
    {  MOD ,              XK_Up,         cursor_move,       {.i=TWOBWM_CURSOR_UP_SLOW}},						// super + up				-->  move cursor up (slow)
    {  MOD ,              XK_Down,       cursor_move,       {.i=TWOBWM_CURSOR_DOWN_SLOW}},						// super + down				-->  move cursor down (slow)
    {  MOD ,              XK_Right,      cursor_move,       {.i=TWOBWM_CURSOR_RIGHT_SLOW}},						// super + right			-->  move cursor right (slow)
    {  MOD ,              XK_Left,       cursor_move,       {.i=TWOBWM_CURSOR_LEFT_SLOW}},						// super + left				-->  move cursor left (slow)
																												// TELEPORT CURRENTLY SELECTED WINDOW
    {  MOD ,              XK_y,          teleport,          {.i=TWOBWM_TELEPORT_TOP_LEFT}},						// super + y				-->  teleport to top left corner
    {  MOD ,              XK_u,          teleport,          {.i=TWOBWM_TELEPORT_TOP_RIGHT}},					// super + u				-->  teleport to top right corner
    {  MOD ,              XK_b,          teleport,          {.i=TWOBWM_TELEPORT_BOTTOM_LEFT}},					// super + b				-->  teleport to bottom left corner
    {  MOD ,              XK_n,          teleport,          {.i=TWOBWM_TELEPORT_BOTTOM_RIGHT}},					// super + n				-->  teleport to bottom right corner
    {  MOD ,              XK_g,          teleport,          {.i=TWOBWM_TELEPORT_CENTER}},						// super + g				-->  teleport to center
    {  MOD |SHIFT,        XK_g,          teleport,          {.i=TWOBWM_TELEPORT_CENTER_Y}},						// super + shift + g		-->  center y-axis
    {  MOD |CONTROL,      XK_g,          teleport,          {.i=TWOBWM_TELEPORT_CENTER_X}},						// super + ctrl + g			-->  center x-axis
    {  MOD ,              XK_m,          maxvert_hor,       {.i=TWOBWM_MAXIMIZE_VERTICALLY}},					// super + m				-->  maximise vertically
    {  MOD |SHIFT,        XK_m,          maxvert_hor,       {.i=TWOBWM_MAXIMIZE_HORIZONTALLY}},					// super + shift + m		-->  maximise horizontally
    {  MOD |SHIFT,        XK_y,          maxhalf,           {.i=TWOBWM_MAXHALF_VERTICAL_LEFT}},					// super + shift + y		-->  maximise and move to left half
    {  MOD |SHIFT,        XK_u,          maxhalf,           {.i=TWOBWM_MAXHALF_VERTICAL_RIGHT}},				// super + shift + u		-->  maximise and move to right half
    {  MOD |SHIFT,        XK_b,          maxhalf,           {.i=TWOBWM_MAXHALF_HORIZONTAL_BOTTOM}},				// super + shift + b		-->  maximise and move to bottom half
    {  MOD |SHIFT,        XK_n,          maxhalf,           {.i=TWOBWM_MAXHALF_HORIZONTAL_TOP}},				// super + shift + n		-->  maximise and move to top half
																												// FOLDING
    {  MOD |SHIFT|CONTROL,XK_y,          maxhalf,           {.i=TWOBWM_MAXHALF_FOLD_VERTICAL}},					// super + shift + ctrl + y	-->  fold half vertically
    {  MOD |SHIFT|CONTROL,XK_b,          maxhalf,           {.i=TWOBWM_MAXHALF_FOLD_HORIZONTAL}},				// super + shift + ctrl + b	-->  fold half horizontally
    {  MOD |SHIFT|CONTROL,XK_u,          maxhalf,           {.i=TWOBWM_MAXHALF_UNFOLD_VERTICAL}},				// super + shift + ctrl + u	-->  unfold vertically
    {  MOD |SHIFT|CONTROL,XK_n,          maxhalf,           {.i=TWOBWM_MAXHALF_UNFOLD_HORIZONTAL}},				// super + shift + ctrl + n	-->  unfold horizontally
																												// FULLSCREEN
    {  MOD ,              XK_x,         maximize,          {.i=TWOBWM_FULLSCREEN}},								// super + x				-->  fullscreen
    {  MOD |SHIFT ,       XK_x,          maximize,          {.i=TWOBWM_FULLSCREEN_OVERRIDE_OFFSETS}},			// super + shift + x		-->  fullscreen (override offsets)
																												// CHANGE SCREEN
    {  MOD ,              XK_comma,      changescreen,      {.i=TWOBWM_NEXT_SCREEN}},							// super + ,				-->  next screen
    {  MOD ,              XK_period,     changescreen,      {.i=TWOBWM_PREVIOUS_SCREEN}},						// super + .				-->  previous screen
																												// CHANGE WORKSPACE/MOVE WINDOW TO NEXT/PREVIOUS WORKSPACE
    {  MOD ,              XK_v,          nextworkspace,     {}},												// super + v				-->  next workspace
    {  MOD ,              XK_c,          prevworkspace,     {}},												// super + c				-->  previous workspace
    {  MOD |SHIFT ,       XK_v,          sendtonextworkspace,{}},												// super + shift + v		-->  move window to next workspace
    {  MOD |SHIFT ,       XK_c,          sendtoprevworkspace,{}},												// super + shift + c		-->  move window to previous workspace
    {  MOD ,              XK_i,          hide,              {}},												// super + i				-->  iconify the window
    {  MOD ,              XK_a,          unkillable,        {}},												// super + a				-->  make window unkillable
    {  MOD,               XK_t,          always_on_top,     {}},												// super + t				-->  make window always appear on top
    {  MOD ,              XK_f,          fix,               {}},												// super + f				-->  make window appear on all workspaces
																												// 2BWM COMMANDS
    {  MOD |CONTROL,      XK_q,          twobwm_exit,       {.i=0}},											// super + ctrl + q			-->  exit 2bwm
    {  MOD |CONTROL,      XK_r,          twobwm_restart,    {.i=0}},											// super + ctrl + r			-->  restart 2bwm
    {  MOD ,              XK_r,          raiseorlower,      {}},												// super + r				-->  raise or lower window
    {  MOD ,              XK_space,      halfandcentered,   {.i=0}},											// super + space			-->  'halfandcentered'
																												// START PROGRAMS
    {  MOD ,              XK_w,          start,             {.com = menucmd}},									// super + w				-->  start menucmd
																												// CHANGE CURRENT WORKSPACE
       DESKTOPCHANGE(     XK_1,                             0)													// workspace_1				-->  0
       DESKTOPCHANGE(     XK_2,                             1)													// workspace_2				-->  1
       DESKTOPCHANGE(     XK_3,                             2)													// workspace_3				-->  2
       DESKTOPCHANGE(     XK_4,                             3)													// workspace_4				-->  3
       DESKTOPCHANGE(     XK_5,                             4)													// workspace_5				-->  4
       DESKTOPCHANGE(     XK_6,                             5)													// workspace_6				-->  5
       DESKTOPCHANGE(     XK_7,                             6)													// workspace_7				-->  6
       DESKTOPCHANGE(     XK_8,                             7)													// workspace_8				-->  7
       DESKTOPCHANGE(     XK_9,                             8)													// workspace_9				-->  8
       DESKTOPCHANGE(     XK_0,                             9)													// workspace_0				-->  9
};

static Button buttons[] = {
    {  MOD        ,XCB_BUTTON_INDEX_1,     mousemotion,   {.i=TWOBWM_MOVE}, false},
    {  MOD        ,XCB_BUTTON_INDEX_3,     mousemotion,   {.i=TWOBWM_RESIZE}, false},
    {  0          ,XCB_BUTTON_INDEX_3,     start,         {.com = menucmd}, true},
    {  MOD|SHIFT,  XCB_BUTTON_INDEX_1,     changeworkspace, {.i=0}, false},
    {  MOD|SHIFT,  XCB_BUTTON_INDEX_3,     changeworkspace, {.i=1}, false},
    {  MOD|ALT,    XCB_BUTTON_INDEX_1,     changescreen,    {.i=1}, false},
    {  MOD|ALT,    XCB_BUTTON_INDEX_3,     changescreen,    {.i=0}, false}
};
