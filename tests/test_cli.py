import subprocess

def run(data):
    return subprocess.run(['./courier'], input=data, text=True, capture_output=True, timeout=5).stdout

out = run('4\n101\nAxe\nSalve\n5\n4\n102\nLina\nBoots\n2\n5\n6\n6\n9\n0\n')
assert out.index('Axe') < out.index('Lina')
assert 'Base -> Mid Lane -> Jungle' in out
assert 'Jungle -> Mid Lane' in out
assert 'Pengiriman berhasil' in out
out = run('3\n1\n4\n4\n7\nAxe\nItem\n4\n6\n5\n7\n6\n0\n')
assert 'tidak ditemukan' in out and 'tetap berada di antrean' in out
assert 'dibatalkan' in out and 'Antrean kosong' in out
out = run('4\n1\nA\nI\n1\n4\n1\n2\nB\nJ\n1\n6\n6\n0\n')
assert 'sudah digunakan' in out and 'tanpa perjalanan' in out
print('Semua pengujian integrasi lulus.')
out = run('2\n1\n2\n3\n1\n4\n4\n4\n\nAxe\n \nItem\n99\n4\n6\n0\n')
assert 'Jalur sudah ada' in out and 'Jalur berhasil dihapus' in out
assert 'Input tidak boleh kosong' in out and 'Lokasi tujuan tidak tersedia' in out
assert 'tidak ditemukan' in out
out = run('3\n1\n4\n2\n4\n1\n4\n3\nAxe\nItem\n4\n6\n0\n')
assert 'Jalur berhasil ditambahkan' in out and 'Base -> Bottom Lane' in out
out = run('5\n9\n0\n')
assert 'Antrean kosong' in out and 'Belum ada pengiriman berhasil' in out
print('Validasi input, pemulihan jalur, dan data sesi baru lulus.')
