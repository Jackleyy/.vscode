import '../styles/globals.css'
import type { AppProps } from 'next/app'
import Navbar from '../components/Navbar'
import Head from "next/head"
import { Analytics } from '@vercel/analytics/react';


export default function App({ Component, pageProps }: AppProps) {
  return (
    <div className= 'sb_center'>
      <Analytics />
      <Head>
        <title>Inventory Eye</title>
        {/* <meta name="description" content="Sunny Jayaram's Webside " />
        <link rel="icon" href="IMG_8285 2-modified (1).png" /> */}
      </Head>
      <Navbar />
      <Component {...pageProps} />
    </div>
  )
}
