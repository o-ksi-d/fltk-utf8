// generated by Fast Light User Interface Designer (fluid) version 1.0106

#include "inactive.h"

Fl_Group *the_group=(Fl_Group *)0;

Fl_Menu_Item menu_menu[] = {
 {"item", 0,  0, 0, 0, 0, 0, 14, 56},
 {"item", 0,  0, 0, 0, 0, 0, 14, 56},
 {"item", 0,  0, 0, 0, 0, 0, 14, 56},
 {"item", 0,  0, 0, 0, 0, 0, 14, 56},
 {"item", 0,  0, 0, 0, 0, 0, 14, 56},
 {0,0,0,0,0,0,0,0,0}
};

static void cb_active(Fl_Button*, void*) {
  the_group->activate();
}

static void cb_inactive(Fl_Button*, void*) {
  the_group->deactivate();
}

int main(int argc, char **argv) {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(420, 295);
    w = o;
    { Fl_Group* o = the_group = new Fl_Group(25, 25, 375, 235, "activate()/deactivate() called on this Fl_Group");
      o->box(FL_ENGRAVED_FRAME);
      o->align(FL_ALIGN_TOP|FL_ALIGN_INSIDE);
      new Fl_Button(50, 50, 105, 25, "button");
      { Fl_Group* o = new Fl_Group(50, 100, 105, 85, "Child group");
        o->box(FL_DOWN_FRAME);
        { Fl_Check_Button* o = new Fl_Check_Button(50, 100, 105, 25, "red");
          o->type(102);
          o->down_box(FL_DIAMOND_DOWN_BOX);
          o->labelcolor((Fl_Color)1);
        }
        { Fl_Check_Button* o = new Fl_Check_Button(50, 120, 105, 25, "green");
          o->type(102);
          o->down_box(FL_DIAMOND_DOWN_BOX);
          o->selection_color((Fl_Color)2);
          o->labelcolor((Fl_Color)2);
        }
        { Fl_Check_Button* o = new Fl_Check_Button(50, 140, 105, 25, "blue");
          o->type(102);
          o->down_box(FL_DIAMOND_DOWN_BOX);
          o->selection_color((Fl_Color)4);
          o->labelcolor((Fl_Color)4);
        }
        { Fl_Check_Button* o = new Fl_Check_Button(50, 160, 105, 25, "white");
          o->type(102);
          o->down_box(FL_DIAMOND_DOWN_BOX);
          o->selection_color(FL_BACKGROUND2_COLOR);
          o->labelcolor(FL_BACKGROUND2_COLOR);
        }
        o->end();
      }
      { Fl_Slider* o = new Fl_Slider(165, 50, 24, 150, "Fl_Slider");
        o->value(0.5);
      }
      { Fl_Input* o = new Fl_Input(195, 50, 195, 30);
        o->static_value("Fl_Input");
      }
      { Fl_Menu_Button* o = new Fl_Menu_Button(235, 105, 110, 30, "menu");
        o->menu(menu_menu);
      }
      { Fl_Box* o = new Fl_Box(240, 205, 145, 50, "Fl_Box");
        o->box(FL_EMBOSSED_FRAME);
        o->labeltype(FL_SHADOW_LABEL);
        o->labelfont(3);
        o->labelsize(38);
      }
      { Fl_Value_Output* o = new Fl_Value_Output(255, 165, 130, 30, "value:");
        o->maximum(10000);
        o->step(1);
        o->textfont(5);
        o->textsize(24);
        o->textcolor(4);
      }
      { Fl_Scrollbar* o = new Fl_Scrollbar(40, 220, 180, 20, "scrollbar");
        o->type(1);
        o->maximum(100);
      }
      o->end();
    }
    { Fl_Button* o = new Fl_Button(25, 265, 185, 25, "active");
      o->type(102);
      o->value(1);
      o->callback((Fl_Callback*)cb_active);
    }
    { Fl_Button* o = new Fl_Button(220, 265, 180, 25, "inactive");
      o->type(102);
      o->callback((Fl_Callback*)cb_inactive);
    }
    o->end();
  }
  w->show(argc, argv);
  return Fl::run();
}
