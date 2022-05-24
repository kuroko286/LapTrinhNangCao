# LapTrinhNangCao  #Snake Game
1. Hướng dẫn cài đặt:
  * Cách lấy chương trình: clone project về desktop bằng gitbash : git clone https://github.com/kuroko286/LapTrinhNangCao.git và mở project Snake Game bằng visual studio
  * Cài MinGW-W64 (https://sourceforge.net/projects/mingw-w64/), thư viện đồ họa SDL2 (https://www.libsdl.org/download-2.0.php) và thư viện mở rộng của nó (SDL2_image,  SDL2_ttf)(sdl2_image: https://www.libsdl.org/projects/SDL_image/ ; sdl2_ttf:https://www.libsdl.org/projects/SDL_ttf/release/ ;
  sdl2_mixer: https://www.libsdl.org/projects/SDL_mixer/)
  * setup complier: vào Environment Valiables, chọn path, sau đó thêm các folder bin của các file vừa tải.
  * Mở project property trong vs, chọn vc++ directory và thêm các folder include,lib của các file vừa tải vào directory tương ứng
  * add dependence: linker->input và copy paste SDL2.lib SDL2main.lib SDL2_ttf.lib SDL2_mixer.lib;
  * run file main.cpp để chạy game.
  
2. Mô tả về game:
  Mình clone game rắn săn mồi với những chức năng cơ bản, cho rắn di chuyển theo 4 hướng và ăn thức ăn đồng thời khi đó rắn sẽ dài ra 
3. Các chức năng đã cài đặt:
  - chức năng di chuyển rắn bằng 4 nút mũi tên, p để pause game , r để tiếp tục chơi,esc để thoát game.
  - chức năng ăn mồi,khi rắn ăn được mồi sẽ dài ra và tăng điểm tùy theo mức độ chơi.
  - có 2 mode game là classic và modern. Classic thì rắn sẽ được đi xuyên tường còn modern thì chạm tường sẽ chết. và rắn sẽ chết khi rắn ăn chính mình ở cả 2 mode game.
  - Game sẽ có 5 mức độ với tốc độ rắn sẽ tăng dần.
  - Game có menu để điều hướng game như chơi game, xem điểm cao, xem thông tin tác giả hay thoát game.
  - khi rắn chết sẽ hiện màn hình endGame.khi đó người chơi có thể chọn chơi lại với mức độ và chế độ đã chọn. nếu không thì sẽ quay lại menu.
  - Game sẽ có âm thanh nền và hiệu ứng âm thanh khi ăn mồi hoặc nhấn nút.
  - Bạn có thể hình dung game qua video này: https://www.youtube.com/watch?v=-fwixMaf9fc
 4. Các kỹ thuật lập trình:
   Game có sử dụng đồ họa từ thư viện sdl2, sử dụng vector hay con trỏ, mảng, lớp, cấu trúc để lưu trữ các đối tượng game.
  5. Kết luận:
    Qua quá trình lập trình game mình đã có thể tổng hợp lại kiến thức mà mình đã học từ đầu đến giờ. Biết áp dụng kiến thức đó để làm ra 1 game cơ bản.
    Trong tương lai có thể mình sẽ phát triển thêm các chức năng mới cho game như nhiều người chơi , nhiều loại thức ăn, nhiều loại map,hay sử dụng thêm các thư viện đồ họa khác để cho game đẹp hơn.
