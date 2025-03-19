from gtts import gTTS
from pydub import AudioSegment
from pydub.playback import play

v =gTTS(text="Welcome to Autobotic ... Please scan your temperature and scan the QR code ... or write your name in the log book...... Thank you for your cooperation... please be reminded to social distancing",lang="en")
v.save("welcome.mp3")
music = AudioSegment.from_mp3("welcome.mp3") - 15
play(music)

v =gTTS(text="Selamat datang ke Autobotic ... Sila imbas suhu anda dan imbas kod QR ... atau tulis nama anda di buku log ...... Terima kasih atas kerjasama anda ... peringatan ustuk senstiasa melakukan penjarakan sosial",lang="id")
v.save("welcome2.mp3")
music = AudioSegment.from_mp3("welcome2.mp3") - 15
play(music)
