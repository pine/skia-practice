#include "SkSurface.h"
#include "SkTypeface.h"
#include "SkPath.h"
#include "SkCanvas.h"
#include "SkData.h"
#include "SkImage.h"
#include "SkStream.h"

void drawEmoji(SkCanvas* canvas) {
    // 透過色でクリア
    canvas->clear(SK_ColorTRANSPARENT);

    // フォントを読み込み
    sk_sp<SkTypeface> noto = SkTypeface::MakeFromName("Noto Sans Mono CJK JP Bold", SkFontStyle());

    SkPaint paint1, paint2;

    paint1.setTextSize(64.0f);
    paint1.setAntiAlias(true);
    paint1.setColor(0xffEC71A1);
    paint1.setStyle(SkPaint::kFill_Style);
    paint1.setTextAlign(SkPaint::kCenter_Align);
    paint1.setTypeface(noto);

    // テキスト追加
    const char text1[] = "良さ";
    const char text2[] = "そう";
    canvas->drawString(text1, 64.0f, 64.0f - 4.0f,  paint1);
    canvas->drawString(text2, 64.0f, 128.0f - 4.0f,  paint1);
}

void makeEmoji() {
  int width = 128;
  int height = 128;

  auto surface = SkSurface::MakeRasterN32Premul(width, height);
  auto canvas = surface->getCanvas();

  drawEmoji(canvas);

  sk_sp<SkImage> image(surface->makeImageSnapshot());
  if (!image) abort();

  sk_sp<SkData> pngData(image->encodeToData(SkEncodedImageFormat::kPNG, 100));
  sk_sp<SkData> webpData(image->encodeToData(SkEncodedImageFormat::kWEBP, 100));
  if (!pngData) abort();
  if (!webpData) abort();

  SkFILEWStream webpFh("./emoji.webp");
  SkFILEWStream pngFh("./emoji.png");
  (void)webpFh.write(webpData->data(), webpData->size());
  (void)pngFh.write(pngData->data(), pngData->size());
}

int main (int argc, char * const argv[]) {
    makeEmoji();
    return 0;
}

// vim: se sw=4 ts=4 sts=4 et
