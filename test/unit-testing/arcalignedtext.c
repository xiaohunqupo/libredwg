// DEBUGGING,no coverage yet
#define DWG_TYPE DWG_TYPE_ARCALIGNEDTEXT
#include "common.c"

void
api_process (dwg_object *obj)
{
  int error = 0, isnew;
  // TEXT:
  // BITCODE_RD elevation, thickness, rotation, height, oblique_angle,
  // width_factor,
  //    rdvalue;
  // BITCODE_BS generation, vert_alignment, horiz_alignment, bsvalue;
  // BITCODE_RC dataflags, rcvalue;
  // char *text_value;
  // dwg_point_3d ext;
  // dwg_point_2d pt2d, ins_pt, alignment_pt;
  // ARCALIGNEDTEXT:
  BITCODE_D2T text_size;       /*!< DXF 42 */
  BITCODE_D2T xscale;          /*!< DXF 41 */
  BITCODE_D2T char_spacing;    /*!< DXF 43 */
  BITCODE_T style;             /*!< DXF 7 */
  BITCODE_T text_value;        /*!< DXF 1 */
  BITCODE_T font_name;         /*!< DXF 2 */
  BITCODE_T bigfont_name;      /*!< DXF 3 */
  BITCODE_D2T offset_from_arc; /*!< DXF 44 */
  BITCODE_D2T right_offset;    /*!< DXF 45 */
  BITCODE_D2T left_offset;     /*!< DXF 46 */
  BITCODE_3BD center;          /*!< DXF 10 */
  BITCODE_BD radius;           /*!< DXF 40 */
  BITCODE_BD start_angle;      /*!< DXF 50 */
  BITCODE_BD end_angle;        /*!< DXF 51 */
  BITCODE_3BD extrusion;
  BITCODE_BL color;
  BITCODE_BS is_reverse;       /*!< DXF 70 */
  BITCODE_BS text_direction;   /*!< DXF 71, 1 or 2 */
  BITCODE_BS alignment;        /*!< DXF 72 */
  BITCODE_BS text_position;    /*!< DXF 73, 1 or 2 */
  BITCODE_BS is_bold;          /*!< DXF 74 */
  BITCODE_BS is_italic;        /*!< DXF 75 */
  BITCODE_BS is_underlined;    /*!< DXF 76 */
  BITCODE_BS character_set;    /*!< DXF 77 */
  BITCODE_BS pitch_and_family; /*!< DXF 78 */
  BITCODE_BS is_shx;           /*!< DXF 79 */
  BITCODE_BS wizard_flag;      /*!< DXF 280 */
  BITCODE_H arc_handle;        /*!< DXF 330 */

  Dwg_Version_Type version = obj->parent->header.version;
#ifdef DEBUG_CLASSES
  dwg_ent_arcalignedtext *atext = dwg_object_to_ARCALIGNEDTEXT (obj);

  CHK_ENTITY_UTF8TEXT (atext, ARCALIGNEDTEXT, text_value);
  CHK_ENTITY_UTF8TEXT (atext, ARCALIGNEDTEXT, text_size); // D2T double as TV
  CHK_ENTITY_UTF8TEXT (atext, ARCALIGNEDTEXT, xscale);    // -"-
  CHK_ENTITY_UTF8TEXT (atext, ARCALIGNEDTEXT, char_spacing); // -"-
  CHK_ENTITY_UTF8TEXT (atext, ARCALIGNEDTEXT, style);
  CHK_ENTITY_UTF8TEXT (atext, ARCALIGNEDTEXT, font_name);
  CHK_ENTITY_UTF8TEXT (atext, ARCALIGNEDTEXT, bigfont_name);
  CHK_ENTITY_UTF8TEXT (atext, ARCALIGNEDTEXT,
                       offset_from_arc); // D2T double as TV
  CHK_ENTITY_UTF8TEXT (atext, ARCALIGNEDTEXT, right_offset); // -"-
  CHK_ENTITY_UTF8TEXT (atext, ARCALIGNEDTEXT, left_offset);  // -"-

  CHK_ENTITY_2RD (atext, ARCALIGNEDTEXT, center);
  CHK_ENTITY_3RD (atext, ARCALIGNEDTEXT, extrusion);
  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, radius, BD);
  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, start_angle, BD);
  CHK_ENTITY_MAX (atext, ARCALIGNEDTEXT, start_angle, BD, 6.284);
  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, end_angle, BD);
  CHK_ENTITY_MAX (atext, ARCALIGNEDTEXT, end_angle, BD, 6.284);

  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, color, BL);
  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, is_reverse, BS);
  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, text_direction, BS);
  CHK_ENTITY_MAX (atext, ARCALIGNEDTEXT, text_direction, BS, 2);
  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, alignment, BS);
  CHK_ENTITY_MAX (atext, ARCALIGNEDTEXT, alignment, BS, 4);
  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, text_position, BS);
  CHK_ENTITY_MAX (atext, ARCALIGNEDTEXT, text_position, BS, 2);
  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, is_bold, BS);
  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, is_italic, BS);
  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, is_underlined, BS);
  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, character_set, BS);
  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, pitch_and_family, BS);
  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, is_shx, BS);
  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, wizard_flag, BS);

  CHK_ENTITY_TYPE (atext, ARCALIGNEDTEXT, alignment, BS);
  CHK_ENTITY_UTF8TEXT (atext, ARCALIGNEDTEXT, style);
#endif
}
