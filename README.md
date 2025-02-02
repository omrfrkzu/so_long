<p align="center">
  <img src="https://github.com/jotavare/jotavare/blob/main/42/banners/piscine_and_common_core/github_piscine_and_common_core_banner_so_long.png">
</p>

<p align="center">
	<img src="https://img.shields.io/badge/status-finished-success?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/badge/evaluated-21%20%2F%2001%20%2F%202023-success?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/badge/score-125%20%2F%20100-success?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/github/languages/top/jotavare/so_long?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/github/last-commit/jotavare/so_long?color=%2312bab9&style=flat-square" />
	<a href='https://www.linkedin.com/in/joaoptoliveira' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat-square&logo=Linkedin&logoColor=white&labelColor=0A66C2&color=0A66C2'/></a>
	<a href='https://profile.intra.42.fr/users/jotavare' target="_blank"><img alt='42' src='https://img.shields.io/badge/Porto-100000?style=flat-square&logo=42&logoColor=white&labelColor=000000&color=000000'/></a>
</p>

<p align="center">
	<a href="#hakkinda">Hakkında</a> •
	<a href="#how-to-use">Nasıl Kullanılır</a> •
	<a href="#zorunlu">Zorunlu</a> •
	<a href="#bonus">Bonus</a> •
	<a href="#norminette">Norminette</a> •
	<a href="#katkida-bulunma">Katkıda Bulunma</a> •
	<a href="#lisans">Lisans</a>
</p>

## HAKKINDA
Bu, oyuncunun bir hedefe ulaşmak için labirent benzeri bir ortamda gezinmesi ve engellerden ve düşmanlardan kaçınması gereken 2D bir oyundur. MiniLibX kütüphanesi kullanılarak oluşturulmuştur ve oyun mekaniği, dosya girişi/çıkışı ve temel grafiklerin implementasyonu yapılmıştır.

- [Konu](https://github.com/jotavare/so_long/blob/master/subject/en_subject_so_long.pdf) `PDF`
- [Referanslar](https://github.com/jotavare/42-resources#02-so_long) `GitHub`

## HOW TO USE
#### 1º - Clone the repository
```bash
git clone git@github.com:jotavare/so_long.git
```
#### 2º - Enter the project folder and run `make` or `make bonus`
> **Important:** To run the program, you need to download the MiniLibX.
```bash
cd so_long/so_long
make or make bonus
```

#### 3º - Run the game with a map of your choice
```bash
./so_long [map.ber]
./so_long_bonus [map_bonus.ber]
```
#### MAKEFILE KURALLARI
`make` - so_long dosyalarını derler.  
`make bonus` - so_long_bonus dosyalarını derler.  
`make all`  - Zorunlu + bonus dosyalarını derler.  
`make clean`  - Tüm .o (nesne dosyaları) dosyalarını siler.  
`make fclean`  - Tüm .o (nesne dosyaları) ve .a (çalıştırılabilir) dosyalarını siler.  
`make re` - `fclean` ve `all` kurallarını kullanır.

## ZORUNLU
- [x] MiniLibX kullanılmalı.
- [x] Makefile, kaynak dosyalarını derlemeli ve yeniden bağlama yapmamalıdır.
- [x] Program, `.ber` uzantısıyla biten bir harita tanım dosyasını parametre olarak almalıdır.

#### OYUN
- [x] **Hedef:** Tüm toplar toplanmalı ve en kısa rotayı seçerek çıkışa ulaşılmalıdır.
- [x] `W`, `A`, `S` ve `D` tuşları ana karakteri `yukarı`, `aşağı`, `sol` ve `sağ` hareket ettirmek için kullanılmalıdır.
- [x] Duvarlara girilemez.
- [x] Hareket sayısı, shell ekranında gösterilmelidir.
- [x] 2D görünüm olmalıdır (üstten görünümlü veya profilden).
- [x] Gerçek zamanlı olmasına gerek yoktur.

#### GRAFİK YÖNETİMİ
- [x] Görüntü bir pencerede gösterilmeli ve pencere değişikliklerinde, minimize etme gibi durumlarda düzgün kalmalıdır.
- [x] `ESC` tuşuna basıldığında pencere kapanmalı ve program temiz şekilde çıkmalıdır.
- [x] Pencerenin çarpısına tıklamak da pencereyi kapatmalı ve programı temiz şekilde sonlandırmalıdır.
- [x] MiniLibX'in görsellerinin kullanımı zorunludur.

#### HARİTA BİLEŞENLERİ
- [x] Harita, inşa edilecek 3 bileşeni içermelidir: duvarlar, toplanabilir nesneler ve boş alan.
- [x] Sadece bu 5 karakterle yapılmalıdır:

| Karakterler | Açıklama |
| :--: | :--: |
| `0` | Boş alan.              |
| `1` | Duvar.                     |
| `C` | Toplanabilir nesne.              |
| `E` | Harita çıkışı.                 |
| `P` | Oyuncu başlangıç pozisyonu. |

#### HARİTA DOĞRULAMA
- [x] Harita geçerli olabilmesi için 1 çıkış, en az 1 toplanabilir nesne ve 1 başlangıç pozisyonu içermelidir.
- [x] Harita dikdörtgen olmalıdır.
- [x] Harita, duvarlarla kapalı/çevrelenmiş olmalıdır. Eğer değilse, program bir hata vermelidir.
- [x] Haritada geçerli bir yol olup olmadığı kontrol edilmelidir.
- [x] Program, kurallara uyan her türlü haritayı çözebilecek şekilde tasarlanmalıdır.
- [x] Bir hata/yanlış yapılandırma ile karşılaşıldığında, `Error\n` ve ardından açık bir mesaj verilmelidir.

> Harita `.ber` örneği:
```
111111111111
1001000000C1
100000011101
1P0011E00001
111111111111
```

## BONUS
- [x] Orijinal ek özellikler geliştirin (isteğe bağlı).
- [x] Oyuncu, düşman devriyesine dokunduğunda kaybetsin.
- [x] Sprite animasyonu ekleyin.
- [x] Hareket sayısını doğrudan ekranda gösterin, shell'e yazmak yerine.

## NORMINETTE
> 42 Okulunda, hemen hemen her projenin okulun kodlama standartlarına uygun olarak yazılması beklenir.

```
- No for, do...while, switch, case, goto, ternary operators, or variable-length arrays allowed;
- Each function must be a maximum of 25 lines, not counting the function's curly brackets;
- Each line must be at most 80 columns wide, with comments included;
- A function can take 4 named parameters maximum;
- No assigns and declarations in the same line (unless static);
- You can't declare more than 5 variables per function;
- ...
```


* [42 Norms](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf) - 42 kod normları hakkında bilgi. `PDF`
* [Norminette](https://github.com/42School/norminette) - Kod normlarına uymak için kullanılan araç, 42 tarafından yapılmıştır. `GitHub`
* [42 Header](https://github.com/42Paris/42header) - Vim için 42 başlığı. `GitHub`

## KATKIDA BULUNMA

Herhangi bir sorunla karşılaşırsanız veya iyileştirmelerle ilgili önerileriniz varsa, depoyu çatal oluşturabilir ve bir sorun açabilir veya bir pull request gönderebilirsiniz.

## LİSANS

Bu proje MIT Lisansı altında mevcuttur. Daha fazla bilgi için lütfen [LİSANS](https://github.com/jotavare/so_long/blob/master/LICENSE) dosyasına bakın.
